/*************************************************************************
    > File Name: fibonacciNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-20 19:56:52
 ************************************************************************/
class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int a = 0;
        int b = 1;
        while (N-- > 1)
        {
            int tmp = a + b;
            a = b;
            b = tmp; 
        }
        return b;
    }
};
