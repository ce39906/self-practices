/*************************************************************************
    > File Name: recoverBinarySearchTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-10 19:29:52
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
    void recoverTree(TreeNode* root) {
        first_node = NULL;
        second_node = NULL;
        prev_node = new TreeNode(INT_MIN);
        inorderTraverse(root);
        
        int temp = first_node->val;
        first_node->val = second_node->val;
        second_node->val = temp;
    }
private:
    TreeNode* first_node;
    TreeNode* second_node;
    TreeNode* prev_node;
    void inorderTraverse(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        
        inorderTraverse(root->left);
        
        if (!first_node && prev_node->val >= root->val)
        {
            first_node = prev_node;
        }
        
        if (first_node && prev_node->val >= root->val)
        {
            second_node = root;
        }
        
        prev_node = root;
        inorderTraverse(root->right);
    }
};
