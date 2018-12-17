/*************************************************************************
    > File Name: longestIncreasingSubsequence.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-17 14:14:31
 ************************************************************************/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int size = nums.size();
        if (size <= 1)
        {
            return size;
        }
        
        vector<int> dp(size, 1);
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
