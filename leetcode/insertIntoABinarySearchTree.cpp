/*************************************************************************
    > File Name: insertIntoABinarySearchTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-05-21 10:49:08
 ************************************************************************/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            return new TreeNode(val);
        }

        if (!root->left && !root->right)
        {
            TreeNode* node = new TreeNode(val);
            if (val < root->val)
            {
                root->left = node;
            }
            else
            {
                root->right = node;
            }
            
            return root;
        }

        if (root->val > val)
        {
            TreeNode* left = insertIntoBST(root->left, val);
            root->left = left;
            return root;
        }
        else
        {
            TreeNode* right = insertIntoBST(root->right, val);
            root->right = right;
            return root;
        }
        
        return root;
    }
};
