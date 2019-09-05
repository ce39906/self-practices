/*************************************************************************
    > File Name: nThTribonacciNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 15:38:27
 ************************************************************************/
class Solution {
public:
    int tribonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        if (n < 2)
        {
            return n;
        }
        n -= 2;
        while (n--)
        {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};
