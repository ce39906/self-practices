/*************************************************************************
    > File Name: KthLargestElementInAnArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-03 20:00:32
 ************************************************************************/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while (true)
        {
            int p = partition(nums, left, right);
            if (p == k - 1)
            {
                return nums[p];
            }
            
            if (p < k - 1)
            {
                left = p + 1;    
            }
            else
            {
                right = p - 1;
            }
        }
        // better save than sorry
        return -1;
    }
private:
    int partition(vector<int>& nums,
                  const int left,
                  const int right) const
    {
        int pivot = nums[left];
        int l = left + 1;
        int r = right;
        while (l <= r)
        {
            if (nums[l] < pivot && nums[r] > pivot)
            {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            
            if (nums[l] >= pivot)
            {
                l++;
            }
            
            if (nums[r] <= pivot)
            {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
