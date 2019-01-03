/*************************************************************************
    > File Name: sumOfLeftLeaves.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-03 19:35:20
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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }
private:
    int sumOfLeftLeaves(TreeNode* root, bool left)
    {
        if (!root)
        {
            return 0;
        }
        
        if (!root->left && !root->right)
        {
            return left ? root->val : 0;
        }
        
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
