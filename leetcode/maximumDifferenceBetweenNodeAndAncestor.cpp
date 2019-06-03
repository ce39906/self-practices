/*************************************************************************
    > File Name: maximumDifferenceBetweenNodeAndAncestor.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-03 20:07:19
 ************************************************************************/
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int max_val = INT_MIN;
        int min_val = INT_MAX;
        return help(root, max_val, min_val);
    }
private:
    int help(TreeNode* root, int max_val, int min_val)
    {
        if (!root)
        {
            return max_val - min_val;
        }

        int left = help(root->left, max(root->val, max_val), min(root->val, min_val));
        int right = help(root->right, max(root->val, max_val), min(root->val, min_val));
        return max(left, right);
    }
};
