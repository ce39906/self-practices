/*************************************************************************
    > File Name: binaryPrefixDivisibleBy5.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-24 15:47:52
 ************************************************************************/
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        if (A.empty())
            return {};
        const int n = A.size();
        vector<bool> res(n, false);
        long num = 0;
        for (int i = 0; i < n; i++)
        {
            num = (num << 1) + A[i];
            if (num % 5 == 0)
            {
                res[i] = true;
            }
            num %= 5;
        }

        return res;
    }
};
