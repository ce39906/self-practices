/*************************************************************************
    > File Name: findMinimumInRotatedSortedArrayII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-19 14:45:46
 ************************************************************************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        while (low < high)
        {
            if (nums[low] == nums[high])
            {
                low++;
            }
            else
            {
                if (nums[low] < nums[high])
                {
                    return nums[low];
                }
            
                mid = (low + high) / 2;
                if (nums[mid] <= nums[high])
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        
        return nums[low];
    }
};
