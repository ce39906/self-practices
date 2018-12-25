/*************************************************************************
    > File Name: powerOfFour.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 16:18:31
 ************************************************************************/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & num - 1) == 0 && (num & 0x55555555) != 0;
    }
};
