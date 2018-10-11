/*************************************************************************
    > File Name: binaryTreeLevelOrderTraversal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-11 14:58:19
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
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
            res.emplace_back(std::move(line));
        }
        
        return res;
    }
};
