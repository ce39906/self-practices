/*************************************************************************
    > File Name: findPeakElement.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-19 15:54:34
 ************************************************************************/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low >> 1);
            if (nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};
