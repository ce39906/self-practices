/*************************************************************************
    > File Name: allPossibleFullBinaryTrees.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-22 19:23:13
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if (N & 1 == 0)
        {
            return res;
        }
        
        if (N == 1)
        {
            TreeNode* root = new TreeNode(0);
            res.push_back(root);
            return res;
        }
        
        const int num = N - 1;        
        for (int i = 1; i <= num / 2; i += 2)
        {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(num - i);
            for (const auto& l : left)
            {
                for (const auto& r : right)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                    if (i * 2 != num)
                    {
                        TreeNode* root1 = new TreeNode(0);
                        root1->left = r;
                        root1->right = l;
                        res.push_back(root1);
                    }
                }
            }
        }
        
        return res;
    }
};
