/*************************************************************************
    > File Name: uniqueBinarySearchTreeII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-09 20:00:56
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
        {
            return {};
        }
        
        vector<TreeNode*> res = genTree(1, n);
        return res;
    }
private:
    vector<TreeNode*> genTree(int start, int end)
    {
        vector<TreeNode*> res;
        if (start > end)
        {
            return {NULL};
        }
        
        if (start == end)
        {
            TreeNode* tree = new TreeNode(start);
            res.push_back(tree);
            return res;
        }
        
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*> left_trees = genTree(start, i - 1);
            vector<TreeNode*> right_trees = genTree(i + 1, end);
            for (TreeNode* left_tree : left_trees)
            {
                for (TreeNode* right_tree : right_trees)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_tree;
                    root->right = right_tree;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};
