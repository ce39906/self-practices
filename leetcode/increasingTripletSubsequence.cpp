/*************************************************************************
    > File Name: increasingTripletSubsequence.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 15:03:40
 ************************************************************************/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low = INT_MAX;
        int mid = INT_MAX;
        
        for (const int num : nums)
        {
            if (num < low)
            {
                low = num;
            }
            
            if (num < mid && num > low)
            {
                mid = num;
            }
            
            if (num > mid)
            {
                return true;
            }
        }
        
        return false;
    }
};
