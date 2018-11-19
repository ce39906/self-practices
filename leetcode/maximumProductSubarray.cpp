/*************************************************************************
    > File Name: maximumProductSubarray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-19 14:11:39
 ************************************************************************/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        const int size = nums.size();
        vector<int> max_dp(size);
        vector<int> min_dp(size);
        
        max_dp[0] = nums.front();
        min_dp[0] = nums.front();
        
        for (int i = 1; i < size; i++)
        {
            max_dp[i] = max(nums[i], max(nums[i] * max_dp[i - 1], nums[i] * min_dp[i - 1]));
            min_dp[i] = min(nums[i], min(nums[i] * max_dp[i - 1], nums[i] * min_dp[i - 1]));
        }
        
        int max1 = *std::max_element(max_dp.begin(), max_dp.end());
        int max2 = *std::max_element(min_dp.begin(), min_dp.end());
        
        return max(max1, max2);
    }
};
