/*************************************************************************
    > File Name: subarraySumEqualsK.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-10 15:56:43
 ************************************************************************/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> pre_sums;
        pre_sums[0] = 1;
        for (const int num : nums)
        {
            sum += num;
            if (pre_sums.count(sum - k))
            {
                res += pre_sums[sum - k];
            }
            pre_sums[sum]++;
        }

        return res;
    }
};
