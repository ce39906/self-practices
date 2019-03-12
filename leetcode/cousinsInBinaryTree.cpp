/*************************************************************************
    > File Name: cousinsInBinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-08 17:17:33
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root)
        {
            return false;
        }

        queue<TreeNode*> que;
        que.push(root);
        int depth, x_depth, y_depth = 0;
        int x_father, y_father;
        while (!que.empty())
        {
            depth++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* front = que.front();
                que.pop();
                if (front->val == x)
                {
                    x_depth = depth;
                }

                if (front->val == y)
                {
                    y_depth = depth;
                }

                if (front->left)
                {
                    if (front->left->val == x)
                    {
                        x_father = front->val;
                    }

                    if (front->left->val == y)
                    {
                        y_father = front->val;
                    }

                    que.push(front->left);
                }

                if (front->right)
                {
                    if (front->right->val == x)
                    {
                        x_father = front->val;
                    }

                    if (front->right->val == y)
                    {
                        y_father = front->val;
                    }

                    que.push(front->right);
                }
            }
        }

        return x_depth == y_depth && x_father != y_father;
    }

};
