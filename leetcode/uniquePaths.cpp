/*************************************************************************
    > File Name: uniquePaths.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-27 19:27:29
 ************************************************************************/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i * j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
