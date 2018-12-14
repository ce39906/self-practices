/*************************************************************************
    > File Name: perfectSquares.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-13 17:51:43
 ************************************************************************/
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0)
        {
            return 0;
        }
        
        vector<int> candidates;
        for (int i = sqrt(n); i >= 0; i--)
        {
            candidates.push_back(i * i);
        }
           
        vector<int> path;
        int res = INT_MAX;
        dfs(candidates, 0, n, path, res);
        
        return res;
    }

private:
    void dfs(const vector<int>& candidates,
             const int cur,
             const int remind,
             vector<int>& path,
             int& res) const
    {
        if (remind < 0 || path.size() >= res)
        {
            return;
        }
    
        if (remind == 0)
        {
            res = min(res, static_cast<int>(path.size()));
            return;
        }
        
        path.push_back(candidates[cur]);
        for (int i = cur; i < candidates.size(); i++)
        {
            dfs(candidates, i, remind - candidates[i], path, res);
        }
        path.pop_back();
    }
    
};
