/*************************************************************************
    > File Name: increasingOrderSearchTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-08 19:35:15
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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) 
        {
            return root;
        }
        
        if (!root->left && !root->right)
        {
            return root;
        }
        
        TreeNode* left_root = increasingBST(root->left);
        TreeNode* right_root = increasingBST(root->right);
        root->right = right_root;
        root->left = NULL;
        if (!left_root)
        {
            return root;
        }
        
        TreeNode* right_most = left_root;
        while (right_most->right)
        {
            right_most->left = NULL;
            right_most = right_most->right;
        }
        right_most->right = root;
        return left_root;
    }
};
