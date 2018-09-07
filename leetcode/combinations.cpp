/*************************************************************************
    > File Name: combinations.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-07 16:20:36
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(n, k, 1, path, res);
        return res;
    }
    
    void dfs(const int n,
             const int k,
             const int cur,
             vector<int>& path,
             vector<vector<int>>& res) const
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        
        for (int i = cur; i <= n; i++)
        {
            path.push_back(i);
            dfs(n, k, i + 1, path, res);
            path.pop_back();
        }
    }
};
