/*************************************************************************
    > File Name: minimumDepthOfBinaryTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-16 19:19:01
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
    int minDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while (!que.empty())
        {
            res++;
            const int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* front = que.front();
                if (front->left)
                {
                    que.push(front->left);
                }
                if (front->right)
                {
                    que.push(front->right);
                }
                que.pop();
                if (!front->left && !front->right)
                {
                    return res;
                }
            }
        }
        
        return res;
    }
};
