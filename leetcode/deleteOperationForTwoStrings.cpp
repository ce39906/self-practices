/*************************************************************************
    > File Name: deleteOperationForTwoStrings.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-18 11:14:07
 ************************************************************************/
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size();
        const int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return m + n - 2 * dp[m][n];
    }
};
