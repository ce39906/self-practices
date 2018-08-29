/*************************************************************************
    > File Name: sqrtX.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-29 19:50:54
 ************************************************************************/
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
        {
            return x;
        }
        
        int low = 1;
        int high = x / 2;
        while (low <= high)
        {
            long mid = low + (high - low >> 1);
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return high;
    }
};
