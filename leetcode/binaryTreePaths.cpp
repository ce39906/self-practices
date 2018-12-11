/*************************************************************************
    > File Name: binaryTreePaths.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-11 19:12:43
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<vector<int>> paths;
        dfs(root, path, paths);
        vector<string> res;
        for (const auto& path : paths)
        {
            string str = "";
            for (int i = 0; i < path.size(); i++)
            {
                str += to_string(path[i]);
                if (i != path.size() - 1)
                {
                    str += "->";
                }
            }
            
            res.emplace_back(std::move(str));
        }
        
        return res;
    }
private:
    void dfs(TreeNode* root,
             vector<int>& path,
             vector<vector<int>>& paths) const
    {
        if (!root)
        {
            return;
        }
        
        if (!root->left && !root->right)
        {
            path.push_back(root->val);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        
        path.push_back(root->val);
        dfs(root->left, path, paths);
        dfs(root->right, path, paths);
        path.pop_back();
    }
};
