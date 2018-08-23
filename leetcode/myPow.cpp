/*************************************************************************
    > File Name: myPow.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-23 17:00:05
 ************************************************************************/
class Solution {
public:
    double myPow(double x, int n) {
        long long_n = n;
        if (x == 0.)
        {
            return 0.;
        }
        
        if (long_n == 0)
        {
            return 1.0;
        }
        
        if (long_n < 0)
        {
            long_n = -long_n;
            x = 1 / x;
        }
        
        // odd
        if (long_n & 1)
        {
            
            return x * myPow(x * x, long_n / 2);
        }
        else
        {
            return myPow(x * x, long_n / 2);
        }
    }
};
