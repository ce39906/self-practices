/*************************************************************************
    > File Name: searchInRotatedSortedArrayII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-10 16:32:11
 ************************************************************************/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right)
        {
            int mid = left + (right - left >> 1);
            if (nums[mid] == target)
            {
                return true;
            }
            
            if (nums[left] == nums[mid] && nums[right] == nums[mid])
            {
                left++;
                right--;
            }
            else if (nums[left] <= nums[mid]) // left part sorted
            {
                if (target >= nums[left] && target <= nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else // right part sorted
            {
                if (target >= nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        
        return false;
    }
};
