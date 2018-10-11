/*************************************************************************
    > File Name: symmetricTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-11 14:52:54
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        
        if (!root->left && !root->right)
        {
            return true;
        }
        
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode* root1, TreeNode* root2) const
    {
        if (!root1 && !root2)
        {
            return true;
        }
        
        if (!root1 || !root2)
        {
            return false;
        }
        
        if (root1->val != root2->val)
        {
            return false;
        }
        
        bool left_symmetric = isSymmetric(root1->left, root2->right);
        bool right_symmetric = isSymmetric(root1->right, root2->left);
        
        return left_symmetric && right_symmetric;
    }
};
