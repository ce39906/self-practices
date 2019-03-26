/*************************************************************************
    > File Name: subarraySumsDivisibleByK.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-21 15:49:48
 ************************************************************************/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> prefix_sums;
        prefix_sums[0] = 1;
        int res = 0;
        int sum = 0;
        for (const int a : A)
        {
            sum += a;
            sum %= K;
            if (sum < 0)
            {
                sum += K;
            }

            if (prefix_sums.count(sum))
            {
                res += prefix_sums[sum];
            }
            prefix_sums[sum]++;
        }
        return res;
    }
};
