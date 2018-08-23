/*************************************************************************
    > File Name: maximumSubarray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-23 18:59:47
 ************************************************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        return maxSubArray(nums, 0, n - 1);
    }
private:
    int maxSubArray(const vector<int>& nums,
                    const int left,
                    const int right) const
    {
        if (left > right)
        {
            return INT_MIN;
        }
        
        if (left == right)
        {
            return nums[left];
        }
        
        const int mid = left + ((right - left) >> 1);
        const int tmp = max(maxSubArray(nums, left, mid - 1), 
                            maxSubArray(nums, mid + 1, right));
        const int cross_max = crossMax(nums, mid, left, right);
        return max(tmp, cross_max);
    }
    
    int crossMax(const vector<int>& nums,
                 const int mid,
                 const int left,
                 const int right) const
    {
        int left_sum = 0;
        int tmp = 0;
        for (int i = mid - 1; i >= left; i--)
        {
            tmp += nums[i];
            left_sum = max(tmp, left_sum);
        }
        
        int right_sum = 0;
        tmp = 0;
        for (int i = mid + 1; i <= right; i++)
        {
            tmp += nums[i];
            right_sum = max(tmp, right_sum);
        }
        return left_sum + nums[mid] + right_sum;
    }
};

// dp solution

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        for (size_t i = 1; i < nums.size(); i++)
        {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
        }

        return *max_element(nums.begin(), nums.end());
    }
};
