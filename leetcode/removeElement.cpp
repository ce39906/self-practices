/*************************************************************************
    > File Name: removeElement.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-15 12:33:10
 ************************************************************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (const int num : nums)
        {
            if (num != val)
            {
                nums[j++] = num;
            }
        }
        
        return j;
    }
};
