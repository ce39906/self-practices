/*************************************************************************
    > File Name: binaryTreeZigzagLevelOrderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-11 15:09:28
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        
        bool reverse = false;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            const int size = que.size();
            vector<int> line;
            line.reserve(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode* front = que.front();
                que.pop();
                line.push_back(front->val);
                if (front->left)
                {
                    que.push(front->left);
                }
                
                if (front->right)
                {
                    que.push(front->right);
                }
            }
            
            if (reverse)
            {
                std::reverse(line.begin(), line.end());
            }
            
            reverse = !reverse;
            res.emplace_back(std::move(line));
        }
        
        return res;
    }
};
