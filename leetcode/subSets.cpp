/*************************************************************************
    > File Name: subSets.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-07 16:41:50
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // subset count is 2^n
        // we can sovle this problem by bitmap
        vector<vector<int>> res;
        const int n = nums.size();
        if (!n)
        {
            return res;
        }
        const int total = 1 << n;
        res.reserve(total);
        for (int i = 0; i < total; i++)
        {
            vector<int> subset;
            int num = i;
            // sweep n bit in i
            for (int j = 0; j < n; j++)
            {
                int last_bit = num & 1;
                num >>= 1;
                if (last_bit)
                {
                    subset.push_back(nums[j]);
                }
            }
            
            res.emplace_back(std::move(subset));
        }
        
        return res;
    }
};
