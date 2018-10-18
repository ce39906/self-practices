/*************************************************************************
    > File Name: flattenBinaryTreeToLinkedList.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-18 16:33:39
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
    void flatten(TreeNode* root) {
       recursive_flatten(root);
    }
private:
    TreeNode* recursive_flatten(TreeNode* root) const
    {
        if (!root || (!root->left && !root->right))
        {
            return root;
        }
        
        TreeNode* flatten_left = recursive_flatten(root->left);
        TreeNode* flatten_right = recursive_flatten(root->right);
        
        if (!flatten_left)
        {
            root->right = flatten_right;
            return root;
        }
        
        root->right = flatten_left;
        root->left = NULL;
        TreeNode* cur = flatten_left;
        while (cur && cur->right)
        {
            cur = cur->right;
        }
        
        if (cur)
        {
            cur->right = flatten_right;
        }
        
        return root;
    }
};
