/*************************************************************************
    > File Name: sumRootToLeafNumbers.cpp
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2018-11-04 19:45:09
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
    int sumNumbers(TreeNode* root) {
        int res = sumNumbers(0, root);
        return res;
    }
    
    int sumNumbers(int father, TreeNode* root) const
    {
        if (!root)
        {
            return 0;
        }
        
        int cur = father * 10 + root->val;
        if (!root->left && !root->right)
        {
            return cur;
        }
        
        int left = sumNumbers(cur, root->left);
        int right = sumNumbers(cur, root->right);
        return left + right;
    }
};
