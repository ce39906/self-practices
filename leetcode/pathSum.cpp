/*************************************************************************
    > File Name: pathSum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-18 15:47:03
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return false;
        }
        
        if (!root->left && !root->right)
        {
            return root->val == sum;
        }
        
        bool left_res = hasPathSum(root->left, sum - root->val);
        bool right_res = hasPathSum(root->right, sum - root->val);
        
        return left_res || right_res;
    }
};
