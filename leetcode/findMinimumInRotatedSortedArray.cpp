/*************************************************************************
    > File Name: findMinimumInRotatedSortedArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-19 14:26:28
 ************************************************************************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        while (low < high)
        {
            if (nums[low] < nums[high])
            {
                return nums[low];
            }
            
            mid = (low + high) / 2;
            if (nums[mid] >= nums[low])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return nums[low];
    }
};
