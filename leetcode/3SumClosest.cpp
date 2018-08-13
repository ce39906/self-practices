/*************************************************************************
    > File Name: 3SumClosest.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-13 16:33:50
 ************************************************************************/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // safety guard
        if (nums.size() < 3)
        {
            return target;
        }
        
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; i++)
        {
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high)
            {
                const int sum = nums[i] + nums[low] + nums[high];
                if (sum < target)
                {
                    low++;
                }
                else if (sum > target)
                {
                    high--;
                }
                else
                {
                    return target;
                }
                if (abs(sum - target) < abs(res - target))
                {
                    res = sum;
                }
            }
        }
        
        return res;
    }
};
