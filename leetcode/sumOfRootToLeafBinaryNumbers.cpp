/*************************************************************************
    > File Name: sumOfRootToLeafBinaryNumbers.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-21 16:04:11
 ************************************************************************/
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, root->val, res);
        return res;
    }

private:
    void dfs(TreeNode* root,
             int val,
             int& res)
    {
        if (!root->left && !root->right)
        {
            res += val;
            return;
        }

        if (root->left)
        {
            dfs(root->left, val * 2 + root->left->val, res);
        }

        if (root->right)
        {
            dfs(root->right, val * 2 + root->right->val, res);
        }
    }
};
