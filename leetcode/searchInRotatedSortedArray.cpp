/*************************************************************************
    > File Name: searchInRotatedSortedArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-17 17:14:01
 ************************************************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return -1;
        }
        
        int low = 0, high = nums.size();
        
        while (low < high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            // left part sorted
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else // right part sorted
            {
                if (nums[mid] <= target && target <= nums[high - 1])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
        }
        return -1;
    }
};
