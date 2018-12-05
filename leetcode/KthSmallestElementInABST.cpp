/*************************************************************************
    > File Name: KthSmallestElementInABST.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-05 19:34:39
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
    int kthSmallest(TreeNode* root, int k) {
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
            
            if (!s.empty())
            {
                TreeNode* top = s.top();
                if (--k == 0)
                {
                    return top->val;
                }
                s.pop();
                if (top->right)
                {
                    cur = top->right;
                }
            }
        }
        
        return 0;
    }
};
