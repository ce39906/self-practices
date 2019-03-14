/*************************************************************************
    > File Name: minimumCostForTickets.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-14 11:29:27
 ************************************************************************/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel_days(days.begin(), days.end());
        vector<int> dp(366, 0);
        for (int i = 1; i < 366; i++)
        {
            if (!travel_days.count(i))
            {
                dp[i] = dp[i - 1];
                continue;
            }
            dp[i] = min(dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1]);
            dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
        }

        return dp[365];
    }
};
