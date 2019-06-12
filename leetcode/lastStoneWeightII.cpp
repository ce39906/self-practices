/*************************************************************************
    > File Name: lastStoneWeightII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-10 15:00:03
 ************************************************************************/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int S = 0, S2 = 0;
        S = accumulate(stones.begin(), stones.end(), 0);
        const int n = stones.size();
        vector<vector<bool>> dp(S + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = true;
        }

        for (int s = 1; s <= S / 2; s++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (dp[s][i - 1] || (s >= stones[i - 1] && dp[s - stones[i - 1]][i - 1]))
                {
                    dp[s][i] = true;
                    S2 = max(s, S2);
                }
            }
        }

        return S - 2 * S2;
    }
};
