/*************************************************************************
    > File Name: rangeSumOfBST.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-21 11:10:29
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        if (!root)
        {
            return 0;
        }
            
        stack<TreeNode*> s;
        TreeNode* cur = root;
        
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            TreeNode* front = s.top();
            s.pop();
            if (front->val >= L && front->val <= R)
            {
                res += front->val;
            }
            
            cur = front->right;
        }
        
        return res;
    }
};
