/*************************************************************************
    > File Name: partitionToKEqualSumSubsets.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-19 14:48:22
 ************************************************************************/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        vector<int> visited(nums.size(), 0);
        return dfs(nums, visited, sum / k, k, 0, 0, 0);
    }

private:
    bool dfs(const vector<int>& nums,
             vector<int>& visited,
             const int target,
             const int k,
             int start,
             int cur_sum,
             int cur_num)
    {
        if (k == 1)
        {
            return true;
        }

        if (cur_sum == target && cur_num > 0)
        {
            return dfs(nums, visited, target, k - 1, 0, 0, 0);
        }

        for (int i = start; i < nums.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }
            visited[i] = 1;
            if (dfs(nums, visited, target, k, i + 1, cur_sum + nums[i], cur_num + 1))
            {
                return true;
            }
            visited[i] = 0;
        }

        return false;
    }
};
