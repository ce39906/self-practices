/*************************************************************************
    > File Name: invertBinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-05 16:55:24
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
        {
            return root;
        }
        
        TreeNode* left_tree = invertTree(root->left);
        TreeNode* right_tree = invertTree(root->right);
        
        root->left = right_tree;
        root->right = left_tree;
        
        return root;
    }
};
