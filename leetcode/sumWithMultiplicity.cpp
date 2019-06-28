/*************************************************************************
    > File Name: sumWithMultiplicity.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-28 11:53:39
 ************************************************************************/
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, int> two_sums;
        const int n = A.size();
        const int mod = 1000000007;
        long res = 0;
        for (int k = 0; k < n; k++)
        {   
            int num = target - A[k];
            if (two_sums.count(num))
            {
                res += two_sums[num];
            }
            for (int i = 0; i < k; i++)
            {
                num = A[i] + A[k];
                two_sums[num]++;
            }
        }
        return res % mod;
    }
};
