/*************************************************************************
    > File Name: lowestCommonAncestorOfABinarySearchTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-06 12:01:35
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
        {
            return root;
        }
        
        if (root == p || root == q)
        {
            return root;
        }
        
        if ((p->val - root->val) * (q->val - root->val) <= 0)
        {
            return root;
        }
        
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        // better save than sorry
        return NULL;
    }
};
