/*************************************************************************
    > File Name: houseRobberIII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 15:06:04
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
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        pair<int, int> rob_or_not = robOrNot(root);
        return max(rob_or_not.first, rob_or_not.second);
    }
private:
    pair<int, int> robOrNot(TreeNode* root)
    {
        if (root == NULL) return {0,0};
        const pair<int, int> left = robOrNot(root->left);
        const pair<int, int> right = robOrNot(root->right);
        int rob_root = left.second + right.second + root->val;
        int not_rob_root = max(left.first, left.second) + max(right.first, right.second);
        return {rob_root, not_rob_root};
    }
};
