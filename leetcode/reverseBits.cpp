/*************************************************************************
    > File Name: reverseBits.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 15:43:25
 ************************************************************************/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 0;
        int j = 31;
        while (i < 32)
        {
            uint32_t last_bit = 1 & n;
            res |= (last_bit << j);
            j--;
            i++;
            n >>= 1;
        }
        return res;
    }
};
