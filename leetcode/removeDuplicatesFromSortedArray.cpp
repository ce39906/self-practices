/*************************************************************************
    > File Name: removeDuplicatesFromSortedArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-15 12:26:54
 ************************************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        int j = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[j])
            {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }
};
