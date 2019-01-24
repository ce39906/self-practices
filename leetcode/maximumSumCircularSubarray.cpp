/*************************************************************************
    > File Name: maximumSumCircularSubarray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-24 16:13:33
 ************************************************************************/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        vector<int> max_dp(A);
        vector<int> min_dp(A);
        int sum = 0;
        
        for (int i = 0; i < A.size(); i++)
        {
            sum += A[i];
            if (i == 0)
            {
                continue;
            }
            
            max_dp[i] = max(max_dp[i], max_dp[i] + max_dp[i - 1]);
            min_dp[i] = min(min_dp[i], min_dp[i] + min_dp[i - 1]);
        }
        
        int max_subarr = *max_element(max_dp.begin(), max_dp.end());
        int min_subarr = *min_element(min_dp.begin() + 1, min_dp.end() - 1);
        
        return max(sum - min_subarr, max_subarr);
    }
};
