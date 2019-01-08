/*************************************************************************
    > File Name: pathSumIII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-08 17:52:23
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
    int pathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return 0;
        }
        
        return findPath(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int findPath(TreeNode* root, int sum)
    {
        if (!root)
        {
            return 0;
        }
        int res = 0;
        if (sum == root->val)
        {
            res++;
        }
        
        res += findPath(root->left, sum - root->val);
        res += findPath(root->right, sum - root->val);
        
        return res;
    }
};
