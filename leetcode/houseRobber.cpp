/*************************************************************************
    > File Name: houseRobber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 16:57:59
 ************************************************************************/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        const int n = nums.size();
        vector<pair<int, int>> dp(n);
        dp.front().first = nums.front();
        dp.front().second = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            const int rob_last = dp[i - 1].first;
            const int not_rob_last = dp[i - 1].second;
            dp[i].first = not_rob_last + nums[i];
            dp[i].second = max(rob_last, not_rob_last);
        }
        
        return max(dp.back().first, dp.back().second);
    }
};
