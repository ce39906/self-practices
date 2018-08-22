/*************************************************************************
    > File Name: permutations.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-22 19:22:16
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return vector<vector<int>>(1, nums);
        
        const int back = nums.back();
        nums.pop_back();
        
        vector<vector<int>> last_res = permute(nums);
        vector<vector<int>> res;
        for (const auto& item : last_res)
        {
            for (int i = 0; i <= item.size(); i++)
            {
                vector<int> tmp = item;
                tmp.insert(tmp.begin() + i, back);
                res.push_back(tmp);
            }
        }
        
        return res;
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
