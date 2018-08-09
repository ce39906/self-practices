/*************************************************************************
    > File Name: 4Sum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-09 12:59:56
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4)
        {
            return res;
        }
        
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            threeSum(nums, nums[i], i + 1, target - nums[i], res);
        }
        return res;
    }
private:
    void threeSum(const vector<int>& nums, 
                  int val,
                  int begin,  
                  int three_sum_target, 
                  vector<vector<int>>& res)
    {
        // nums have already been sorted
        if (nums.size() - begin < 3)
        {
            return;
        }
        for (int i = begin; i < nums.size() - 2; i++)
        {
            if (i > begin && nums[i] == nums[i - 1])
            {
                continue;
            }
            int low = i + 1;
            int high = nums.size() - 1;
            int two_sum_target = three_sum_target - nums[i]; 
            while (low < high)
            {
                if (nums[low] + nums[high] == two_sum_target)
                {
                    res.emplace_back(std::move(vector<int>{val, nums[i], nums[low], nums[high]}));
                    while(low < high && nums[low] == nums[low + 1]) low++;
                    while(low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < two_sum_target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        
    }
    
};
