/*************************************************************************
    > File Name: combinationSumIII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-04 11:28:27
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(k, n, 1, path, res);
        return res;
    }
private:
    void dfs(const int k,
             const int n,
             const int start,
             vector<int>& path,
             vector<vector<int>>& res) const
    {
        if (n < 0)
        {
            return;
        }
        
        if (path.size() == k)
        {
            if (n == 0)
            {
                res.push_back(path);
            }
            return;
        }
        
        for (int i = start; i <= 9; i++)
        {
            path.push_back(i);
            dfs(k, n - i, i + 1, path, res);
            path.pop_back();
        }
    }
};
