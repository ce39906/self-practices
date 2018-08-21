/*************************************************************************
    > File Name: combinationSum.cpp
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2018-08-21 21:58:35
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
             vector<vector<int>>& res) const
    {
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        
        for (int i = cur; i < candidates.size(); i++)
        {
            //prune
            if (sum + candidates[i] > target)
            {
                return;
            }
            
            path.push_back(candidates[i]);
            dfs(candidates, target, i, sum + candidates[i], path, res);
            path.pop_back();
        }
    }
};


