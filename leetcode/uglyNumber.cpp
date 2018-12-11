/*************************************************************************
    > File Name: uglyNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-11 19:28:20
 ************************************************************************/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int total_xor = 0;
        for (const int num : nums)
        {
            total_xor ^= num;
        }
        
        int last_diff_bit = total_xor & (total_xor - 1) ^ total_xor;
        // divide nums to 2 parts by last_diff_bit
        
        int a = 0;
        int b = 0;
        
        for (const int num : nums)
        {
            if (num & last_diff_bit)
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
        }
        
        return {a, b};
    }
};
