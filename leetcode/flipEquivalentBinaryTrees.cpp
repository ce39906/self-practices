/*************************************************************************
    > File Name: flipEquivalentBinaryTrees.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-15 17:33:30
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
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
        
        bool res = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        res |= flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        
        return res;
    }
};
