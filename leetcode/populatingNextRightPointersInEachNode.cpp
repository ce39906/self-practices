/*************************************************************************
    > File Name: populatingNextRightPointersInEachNode.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-18 19:31:22
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
        while (!que.empty())
        {
            int size = que.size();
            TreeLinkNode* prev = NULL;
            for (int i = 0; i < size; i++)
            {
                TreeLinkNode* cur = que.front();
                que.pop();
                if (cur->left)
                {
                    que.push(cur->left);
                }
                
                if (cur->right)
                {
                    que.push(cur->right);
                }
                
                if (i != 0)
                {
                    prev->next = cur;
                }
                
                prev = cur;
            }
        }
    }
};
