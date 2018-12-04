/*************************************************************************
    > File Name: maximalSquare.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-04 13:10:55
 ************************************************************************/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }
        
        const int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int len = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    len = max(len, dp[i][j]);
                }
            }
        }
        
        return len * len;
    }
};
