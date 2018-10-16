/*************************************************************************
    > File Name: balancedBinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-16 17:51:03
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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalanced(root, height);
    }
private:
    bool isBalanced(TreeNode* root, int& height) const
    {
        if (!root)
        {
            height = 0;
            return true;
        }
        
        int left_height, right_height;
        bool left_balanced = isBalanced(root->left, left_height);
        if (!left_balanced)
        {
            return false;
        }
        
        bool right_balanced = isBalanced(root->right, right_height);
        if (!right_balanced)
        {
            return false;
        }
        
        if (abs(left_height - right_height) > 1)
        {
            return false;
        }
        
        height = max(left_height, right_height) + 1;
        return true;
    }
};
