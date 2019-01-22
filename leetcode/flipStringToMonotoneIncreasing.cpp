/*************************************************************************
    > File Name: flipStringToMonotoneIncreasing.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-21 16:46:23
 ************************************************************************/
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        const int n = S.size();
        vector<int> f0(n + 1);
        vector<int> f1(n + 1);
        for (int i = 1, j = n - 1; j >= 0; i++, j--)
        {
            f0[i] = f0[i - 1] + (S[i - 1] == '1');
            f1[j] = f1[j + 1] + (S[j + 1] == '0');
        }
        
        int res = INT_MAX;
        for (int i = 0; i <= n; i++)
        {
            res = min(res, f0[i] + f1[i]);    
        }
        
        return res;
    }
};
