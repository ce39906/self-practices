/*************************************************************************
    > File Name: numberOf1Bits.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 15:45:35
 ************************************************************************/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n)
        {
            if (n & 1)
            {
                res++;
            }
            n >>= 1;
        }
        return res;
    }
};
