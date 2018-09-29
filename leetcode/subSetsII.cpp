/*************************************************************************
    > File Name: subSetsII.cpp
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2018-09-29 22:00:55
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, path, 0, res);
        return res;
    }
private:
    void dfs(const vector<int>& nums,
             vector<int>& path,
             int cur,
             vector<vector<int>>& res)
    {
        res.push_back(path);
        
        for (int i = cur; i < nums.size(); i++)
        {
            if (cur != i && nums[i] == nums[i - 1])
            {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, path, i + 1, res);
            path.pop_back();
        }
    }
};
