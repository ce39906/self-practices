/*************************************************************************
    > File Name: permutationsII.cpp
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2018-08-22 23:03:20
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty())
        {
            return {};
        }
        
        unordered_map<int, int> num_2_cnt;
        for (const int num : nums)
        {
            num_2_cnt[num]++;
        }
                
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums.size(), num_2_cnt, path, res);
        
        return res;
    }
private:
    void dfs(const int size,
             unordered_map<int, int>& num_2_cnt,
             vector<int>& path,
             vector<vector<int>>& res) const
    {
        if (path.size() == size)
        {
            res.push_back(path);
            return;
        }
        
        for (auto it = num_2_cnt.begin(); it != num_2_cnt.end(); ++it)
        {
            if (it->second > 0)
            {
                (it->second)--;
                path.push_back(it->first);
                dfs(size, num_2_cnt, path, res);
                path.pop_back();
                (it->second)++;
            }
        }
    }
};
// use next_permutation directly

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        do
        {
            res.push_back(nums);
        }
        while(next_permutation(nums.begin(), nums.end()));

        return res;
    }
};