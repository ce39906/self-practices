/*************************************************************************
    > File Name: binarySubarraysWithSum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-21 15:53:17
 ************************************************************************/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> prefix_sums;
        prefix_sums[0] = 1;
        int sum = 0;
        int res = 0;
        for (int a : A)
        {
            sum += a;
            
            if (prefix_sums.count(sum - S))
            {
                res += prefix_sums[sum - S];
            }
            
            prefix_sums[sum]++;
        }
        
        return res;
    }
};
