/*************************************************************************
    > File Name: removeDuplicatesFromSortedArrayII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-10 16:00:39
 ************************************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (const int num : nums)
        {
            if (i < 2 || nums[i - 2] != num)
            {
                nums[i++] = num;
            }
        }
        return i;
    }
};
