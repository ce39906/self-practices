/*************************************************************************
    > File Name: binaryTreeMaximumPathSum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-26 19:58:16
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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxSinglePathTreeSum(root, res);
        return res;
    }
private:
    int maxSinglePathTreeSum(TreeNode* root, int& cur_max) const
    {
        if (!root)
        {
            return 0;
        }
        
        int sum = root->val;
        int left_single_path_tree_sum = maxSinglePathTreeSum(root->left, cur_max);
        int right_single_path_tree_sum = maxSinglePathTreeSum(root->right, cur_max);
        if (left_single_path_tree_sum > 0)
        {
            sum += left_single_path_tree_sum;
        }
        if (right_single_path_tree_sum > 0)
        {
            sum += right_single_path_tree_sum;
        }
        
        cur_max = max(cur_max, sum);
        
        int max_left_and_right = max(left_single_path_tree_sum, right_single_path_tree_sum);
        if (max_left_and_right > 0)
        {
            return root->val + max_left_and_right;
        }
        
        return root->val;
    }
};
