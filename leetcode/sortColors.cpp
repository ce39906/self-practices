/*************************************************************************
    > File Name: sortColors.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-06 17:13:54
 ************************************************************************/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int second = nums.size() - 1;
        int zero = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] == 2 && i < second)
            {
                swap(nums[i], nums[second--]);
            }
            while (nums[i] == 0 && i > zero)
            {
                swap(nums[i], nums[zero++]);
            }
        }
    }
};
