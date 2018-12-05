/*************************************************************************
    > File Name: powerOfTwo.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-05 19:51:38
 ************************************************************************/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & n - 1) == 0;
    }
};
