/*************************************************************************
    > File Name: maximumLengthOfPairChain.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-12 11:27:42
 ************************************************************************/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        const int n = pairs.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0 && i - j + 1 > dp[i]; j--)
            {
                if (pairs[i].front() > pairs[j].back())
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
