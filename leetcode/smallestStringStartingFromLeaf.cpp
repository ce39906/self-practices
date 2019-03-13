/*************************************************************************
    > File Name: smallestStringStartingFromLeaf.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-13 15:54:47
 ************************************************************************/
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root)
        {
            return "";
        }

        string path = "";
        vector<string> paths;
        dfs(root, path, paths);
        for (string& path : paths)
        {
            reverse(path.begin(), path.end());
        }

        sort(paths.begin(), paths.end());
        if (paths.size() == 1)
        {
            return paths.front();
        }

        if (paths.front().size() == 1)
        {
            return paths[1];
        }
        
        return paths.front();
    }
private:
    void dfs(TreeNode* root,
             string& path,
             vector<string>& paths) const
    {
        path.push_back('a' + root->val);
        if (!root->left && !root->right)
        {
            paths.push_back(path);
            path.pop_back();
            return;
        }

        if (root->left)
        {
            dfs(root->left, path, paths);
        }
        if (root->right)
        {
            dfs(root->right, path, paths);
        }
        path.pop_back();
    }
};
