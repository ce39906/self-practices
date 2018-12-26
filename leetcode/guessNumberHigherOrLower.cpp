/*************************************************************************
    > File Name: guessNumberHigherOrLower.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-26 20:03:06
 ************************************************************************/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (guess(mid) == 0)
            {
                return mid;
            }
            else if (guess(mid) == 1)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return 1;
    }

};
