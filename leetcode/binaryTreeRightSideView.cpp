/*************************************************************************
    > File Name: binaryTreeRightSideView.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 17:13:29
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
        {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* front = que.front();
                que.pop();
                
                if (front->left)
                {
                    que.push(front->left);
                }
                
                if (front->right)
                {
                    que.push(front->right);
                }
                
                if (i == size - 1)
                {
                    res.push_back(front->val);
                }
            }
        }
        
        return res;
    }
};
