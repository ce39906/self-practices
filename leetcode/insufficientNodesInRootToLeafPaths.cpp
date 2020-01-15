/*************************************************************************
    > File Name: insufficientNodesInRootToLeafPaths.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2020-01-15 17:28:42
 ************************************************************************/
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root)
        {
            return root;
        }

        if (!root->left && !root->right)
        {
            return root->val < limit ? nullptr : root;
        }

        if (root->left)
        {
            root->left = sufficientSubset(root->left, limit - root->val);
        }

        if (root->right)
        {
            root->right = sufficientSubset(root->right, limit - root->val);
        }

        return root->left == root->right ? nullptr : root;
    }
};
