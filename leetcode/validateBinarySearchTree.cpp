/*************************************************************************
    > File Name: validateBinarySearchTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-10 19:12:26
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
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            TreeNode* top = s.top();
            s.pop();
            if (prev && top->val <= prev->val)
            {
                return false;
            }
            prev = top;
            if (top->right)
            {
                cur = top->right;
            }
        }
        
        return true;
    }
};
