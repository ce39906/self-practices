/*************************************************************************
    > File Name: bitwiseAndOfNumbersRange.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 19:07:12
 ************************************************************************/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n)
        {
            n &= (n - 1);
        }
        return n;
    }
};
