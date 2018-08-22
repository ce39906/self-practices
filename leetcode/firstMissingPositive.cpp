/*************************************************************************
    > File Name: firstMissingPositive.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-22 16:56:33
 ************************************************************************/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};
