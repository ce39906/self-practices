/*************************************************************************
    > File Name: binaryTreeLevelOrderTraversalII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-11 19:27:43
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++)
            {
                const TreeNode* front = que.front();
                level[i] = front->val;
                que.pop();
                if (front->left)
                {
                    que.push(front->left);
                }
                if (front->right)
                {
                    que.push(front->right);
                }
            }
            res.emplace_back(std::move(level));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
