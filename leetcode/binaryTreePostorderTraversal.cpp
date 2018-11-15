/*************************************************************************
    > File Name: binaryTreePostorderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-13 13:07:46
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
    vector<int> postorderTraversal(TreeNode* root) {
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
            s.pop();
            res.push_back(top->val);
            if (top->left)
            {
                s.push(top->left);
            }
            if (top->right)
            {
                s.push(top->right);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
