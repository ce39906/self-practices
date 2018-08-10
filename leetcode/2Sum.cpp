/*************************************************************************
    > File Name: 2Sum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-10 10:51:50
 ************************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m.reserve(nums.size());
        for (size_t i = 0 ; i < nums.size(); i++)
        {
            if (m.count(nums[i]))
            {
                return {m[nums[i]], i};
            }
            else
            {
                m.emplace(target - nums[i], i);
            }
        }
        return {};
    }
};
