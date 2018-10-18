/*************************************************************************
    > File Name: pathSumII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-18 16:06:10
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, sum, path, res);
        return res;
    }
private:
    void dfs(TreeNode* root, int cur, vector<int>& path, vector<vector<int>>& res)
    {
        if (!root)
        {
            return;
        }
        
        cur -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && cur == 0)
        {
            res.push_back(path);
        }
        dfs(root->left, cur, path, res);
        dfs(root->right, cur, path, res);
        path.pop_back();
    }
};
