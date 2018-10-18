/*************************************************************************
    > File Name: populatingNextRightPointersInEachNodeII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-18 19:50:17
 ************************************************************************/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
        {
            return;
        }
        queue<TreeLinkNode*> que;
        que.push(root);
        que.push(NULL);
        while (!que.empty())
        {
            TreeLinkNode* cur = que.front();
            que.pop();
            if (cur)
            {
                cur->next = que.front();
                if (cur->left)
                {
                    que.push(cur->left);
                }
                
                if (cur->right)
                {
                    que.push(cur->right);
                }
            }
            else
            {
                if (!que.empty())
                {
                    que.push(NULL);
                }
            }
        }
    }
};
