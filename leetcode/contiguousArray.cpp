/*************************************************************************
    > File Name: contiguousArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-05-05 19:21:38
 ************************************************************************/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = -1;
            }
        }

        int res = 0;
        unordered_map<int, int> prefix_sums;
        prefix_sums[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (prefix_sums.count(sum))
            {
                res = max(res, i - prefix_sums[sum]);
            }
            else
            {
                prefix_sums[sum] = i;
            }
        }
        return res;
    }
};
