/*************************************************************************
    > File Name: containsDuplicateII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-04 12:03:38
 ************************************************************************/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_2_idx;
        for (int i = 0; i < nums.size(); i++)
        {
            if (num_2_idx.count(nums[i]))
            {
                if (i - num_2_idx[nums[i]] <= k)
                {
                    return true;
                }
            }
            num_2_idx[nums[i]] = i;
        }
        return false;
    }
};
