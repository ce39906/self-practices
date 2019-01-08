/*************************************************************************
    > File Name: arrangingCoins.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-08 19:40:46
 ************************************************************************/
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        long sum = 0;
        int res = 0;
        while (sum <= n)
        {
            sum += i;
            i++;
            res++;
        }
        
        return res - 1;
    }
};
