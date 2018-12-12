/*************************************************************************
    > File Name: missingNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-12 19:33:33
 ************************************************************************/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        
        const int sum = n * (n + 1) / 2;
        const int cur_sum = accumulate(nums.begin(), nums.end(), 0);
        
        return sum - cur_sum;
    }
};
