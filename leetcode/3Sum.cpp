/*************************************************************************
    > File Name: 3Sum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-09 12:56:37
 ************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int low = i + 1;
                int high = nums.size() - 1;
                int target = -nums[i];
                while (low < high)
                {
                    if (nums[low] + nums[high] == target)
                    {
                        res.emplace_back(std::move(vector<int>{nums[i], nums[low], nums[high]}));
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        while (low < high && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                    }
                    else if (nums[low] + nums[high] > target)
                    {
                        while (low < high && nums[high] == nums[high - 1]) high--;
                        high--;
                    }
                    else
                    {
                        while (low < high && nums[low] == nums[low + 1]) low++;
                        low++;
                    }
                }
            }
        }
        return res;
    }
};
