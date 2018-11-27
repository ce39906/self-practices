/*************************************************************************
    > File Name: countPrimes.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 19:50:51
 ************************************************************************/
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        is_prime[0] = false;
        is_prime[0] = false;
        for (int i = 2; i < sqrt(n); i++)
        {
            if (!is_prime[i])
            {
                continue;
            }
            
            for (int j = i * i; j < n; j += i)
            {
                is_prime[j] = false;
            }
        }
        
        int res = 0;
        for (int i = 2; i < n; i++)
        {
            if (is_prime[i])
            {
                res++;
            }
        }
        
        return res;
    }
};
