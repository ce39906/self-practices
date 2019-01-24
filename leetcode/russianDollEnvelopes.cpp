/*************************************************************************
    > File Name: russianDollEnvelopes.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-24 11:37:57
 ************************************************************************/
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty())
        {
            return 0;
        }
       
        sort(envelopes.begin(), envelopes.end());
        const int n = envelopes.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (   envelopes[i].first > envelopes[j].first
                    && envelopes[i].second > envelopes[j].second)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
