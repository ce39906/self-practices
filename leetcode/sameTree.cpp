/*************************************************************************
    > File Name: sameTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-10 19:34:05
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
        {
            return true;
        }
        
        if (!p || !q)
        {
            return false;
        }
        
        bool res =    p->val == q->val
                   && isSameTree(p->left, q->left)
                   && isSameTree(p->right, q->right);
        return res;
    }
};
