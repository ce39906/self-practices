/*************************************************************************
    > File Name: binaryTreeInorderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-09 19:39:05
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
        {
            return {};
        }
        
        stack<TreeNode*> s;
        TreeNode* cur = root;
        vector<int> res;
        
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            if (!s.empty())
            {
                TreeNode* top = s.top();
                s.pop();
                res.push_back(top->val);
                if (top->right)
                {
                    cur = top->right;
                }
            }
        }
        
        return res;
    }
};
