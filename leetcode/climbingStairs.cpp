/*************************************************************************
    > File Name: climbingStairs.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-29 19:57:04
 ************************************************************************/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
