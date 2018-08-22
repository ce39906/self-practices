/*************************************************************************
    > File Name: combinationSumII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-22 15:19:26
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, target, 0, 0, path, res);
        return res;
    }
private:
    void dfs(const vector<int>& candidates,
             const int target,
             int cur,
             int sum,
             vector<int>& path,
             vector<vector<int>>& res)
    {
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        
        for (int i = cur; i < candidates.size(); i++)
        {
            // prune
            if (sum + candidates[i] > target)
            {
                return;
            }
            
            if (i != cur && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            
            path.push_back(candidates[i]);
            dfs(candidates, target, i + 1, sum + candidates[i], path, res);
            path.pop_back();
        }
    }
};
