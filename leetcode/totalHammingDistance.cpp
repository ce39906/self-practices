/*************************************************************************
    > File Name: totalHammingDistance.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-08 19:29:02
 ************************************************************************/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bit_count(31, 0);
        int res = 0;
        const int n = nums.size();
        for (const int num : nums)
        {
            int musk = 1;
            for (int i = 0; i < 31; i++)
            {
                if (num & musk)
                {
                    bit_count[i]++;
                }
                musk <<= 1;
            }
        }
        for (const int count : bit_count)
        {
            res += count * (n - count);
        }

        return res;
    }

};
