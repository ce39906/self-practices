/*************************************************************************
    > File Name: maximumWidthOfBinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-05-20 14:21:52
 ************************************************************************/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        unsigned res = 0;
        queue<pair<TreeNode*, unsigned>> que;
        que.push(pair<TreeNode*, unsigned>(root, 1));
        while (!que.empty())
        {
            const int size = que.size();
            res = max(res, que.back().second - que.front().second + 1);
            for (int i = 0; i < size; i++)
            {
                pair<TreeNode*, unsigned> front = que.front();
                que.pop();
                TreeNode* node = front.first;
                unsigned idx = front.second;
                if (node->left)
                {
                    que.push(pair<TreeNode*, unsigned>(node->left, idx * 2));
                }

                if (node->right)
                {
                    que.push(pair<TreeNode*, unsigned>(node->right, idx * 2 + 1));
                }
            }
        }

        return res;
    }
};
