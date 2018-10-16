/*************************************************************************
    > File Name: convertSortedArrayToBinarySearchTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-16 16:52:16
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        TreeNode* root = sortedArrayToBST(nums, 0, size);
        return root;
    }
private:
    TreeNode* sortedArrayToBST(const vector<int>& nums, int start, int end) const
    {
        if (start >= end)
        {
            return NULL;
        }
        
        if (start == end - 1)
        {
            TreeNode* root = new TreeNode(nums[start]);
            return root;
        }
        
        int root_idx = start + (end - start >> 1);
        TreeNode* root = new TreeNode(nums[root_idx]);
        TreeNode* left = sortedArrayToBST(nums, start, root_idx);
        TreeNode* right = sortedArrayToBST(nums, root_idx + 1, end);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
};
