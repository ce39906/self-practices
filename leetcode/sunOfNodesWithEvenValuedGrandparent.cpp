/*************************************************************************
    > File Name: sunOfNodesWithEvenValuedGrandparent.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2020-01-20 19:58:07
 ************************************************************************/
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int res = helper(root, 1, 1);
        return res;
    }

    int helper(TreeNode* node, int p, int gp)
    {
        if (!node)
        {
            return 0;
        }

        return helper(node->left, node->val, p) + helper(node->right, node->val, p) + (gp % 2 == 0 ? node->val : 0);
    }
};
