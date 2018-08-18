/*************************************************************************
    > File Name: findFirstAndLastElementInSortedArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-18 12:12:25
 ************************************************************************/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return {-1, -1};
        }
        int low = 0, high = nums.size();
        while (low < high)
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target)
            {
                int left = mid;
                while (left >= 0 && nums[left] == target)
                {
                    left--;
                }
                left = (left == mid ? mid : left + 1);
                int right = mid;
                while (right < nums.size() && nums[right] == target)
                {
                    right++;
                }
                right = (right == mid ? mid : right - 1);
                return {left, right};
            }
            else if (nums[mid] < target)
            {
                int right = mid;
                while (right < nums.size() && nums[right] == nums[mid])
                {
                    right++;
                }
                low = (right == mid ? right + 1 : right);
            }
            else
            {
                int left = mid;
                while (left >= 0 && nums[left] == nums[mid])
                {
                    left--;
                }
                high = (left == mid ? mid : left + 1);
            }
        }
        return {-1, -1};
    }
};
