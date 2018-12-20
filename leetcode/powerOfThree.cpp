/*************************************************************************
    > File Name: powerOfThree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-20 19:03:49
 ************************************************************************/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
        {
            return false;
        }
        
        if (n == 1)
        {
            return true;
        }
        
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};
