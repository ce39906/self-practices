/*************************************************************************
    > File Name: factorialTrailingZeros.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-20 19:21:18
 ************************************************************************/
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n)
        {
            res += n / 5;
            n /= 5;
        }
        
        return res;
    }
};
