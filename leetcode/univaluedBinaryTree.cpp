/*************************************************************************
    > File Name: univaluedBinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-11 10:47:30
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
    bool isUnivalTree(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        
        if (!root->left && !root->right)
        {
            return true;
        }
        
        bool res = true;
        if (root->left)
        {
            res &= (root->left->val == root->val) && isUnivalTree(root->left); 
        }
        
        if (root->right)
        {
            res &= (root->right->val == root->val) && isUnivalTree(root->right);    
        }
        
        return res;
    }
};
