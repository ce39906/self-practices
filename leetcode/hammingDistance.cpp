/*************************************************************************
    > File Name: hammingDistance.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-10 15:28:59
 ************************************************************************/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;
        for (; n; count++)
        {
            n &= n - 1;
        }
        
        return count;
    }
};
