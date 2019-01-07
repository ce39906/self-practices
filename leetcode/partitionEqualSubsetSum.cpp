/*************************************************************************
    > File Name: partitionEqualSubsetSum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-07 16:54:21
 ************************************************************************/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
        {
            return false;
        }
        
        int half = sum >> 1;
        sort(nums.begin(), nums.end(), greater<int>());
        
        bool res = false;
        dfs(nums, 0, half, res);
        return res;
    }
private:
    void dfs(const vector<int>& nums,
             int cur,
             int left,
             bool& res) const
    {
        if (res || left == 0)
        {
            res = true;
            return;
        }
        
        for (int i = cur; i < nums.size(); i++)
        {
            if (left < nums[i])
            {
                return;
            }
            dfs(nums, i + 1, left - nums[i], res);
        }
    }
};
