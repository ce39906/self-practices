/*************************************************************************
    > File Name: deleteNodeInABST.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-09 16:54:58
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
        {
            return root;
        }
        
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (!root->left)
            {
                return root->right;
            }
        
            if (!root->right)
            {
                return root->left;
            }
        
            int min_val = findMin(root->right)->val;
            root->val = min_val;
            root->right = deleteNode(root->right, min_val);
        }
        
        return root;
    }
    
private:
    TreeNode* findMin(TreeNode* root)
    {
        while (root->left)
        {
            root = root->left;
        }
        
        return root;
    }
};
