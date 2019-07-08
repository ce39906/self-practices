/*************************************************************************
    > File Name: distributeCoinsInBinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-07-08 11:16:37
 ************************************************************************/
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        traversal(root, moves);
        return moves;
    }
private:
    int traversal(TreeNode* root, int& moves)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = traversal(root->left, moves);
        int right = traversal(root->right, moves);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};
