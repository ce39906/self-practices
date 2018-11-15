/*************************************************************************
    > File Name: binaryTreePreorderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-13 13:02:57
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
        {
            return {};
        }
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* top = s.top();
            res.push_back(top->val);
            s.pop();
            if (top->right)
            {
                s.push(top->right);
            }
            if (top->left)
            {
                s.push(top->left);
            }
        }
        
        return res;
    }
};
