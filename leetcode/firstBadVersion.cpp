/*************************************************************************
    > File Name: firstBadVersion.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-12 19:57:23
 ************************************************************************/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        
        while (l <= r)
        {
            int mid = l + (r - l >> 1);
            if (isBadVersion(mid))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return l;
    }
};
