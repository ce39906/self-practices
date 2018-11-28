/*************************************************************************
    > File Name: minimumSizeSubarraySum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-28 15:30:52
 ************************************************************************/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        const int n = nums.size();
        int start = 0;
        int sum = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum >= s)
            {
                res = min(res, i - start + 1);
                sum -= nums[start++];
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};
