/*************************************************************************
    > File Name: longestConsecutiveSequence.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-30 20:03:45
 ************************************************************************/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (const int num : nums)
        {
            int left = num - 1;
            int right = num + 1;
            while (s.count(left))
            {
                s.erase(left);
                left--;
            }
            
            while (s.count(right))
            {
                s.erase(right);
                right++;
            }
            res = max(res, right - left - 1);
        }
        return res;
    }
};
