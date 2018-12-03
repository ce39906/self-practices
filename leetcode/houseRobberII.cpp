/*************************************************************************
    > File Name: houseRobberII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-03 19:41:38
 ************************************************************************/
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
        {
            return 0;
        }
        
        if (size == 1)
        {
            return nums.front();    
        }
        
        const vector<int> drop_first(nums.begin() + 1, nums.end());
        const vector<int> drop_last(nums.begin(), nums.end() - 1);
        
        return max(robInALine(drop_first), robInALine(drop_last));
    }
private:
    int robInALine(const vector<int>& nums) const
    {
        int size = nums.size();
        vector<int> dp1(size, 0);
        vector<int> dp2(size, 0);
        dp1[0] = nums.front();
        for (int i = 1; i < size; i++)
        {
            dp1[i] = dp2[i - 1] + nums[i];
            dp2[i] = max(dp1[i - 1], dp2[i - 1]);
        }
        
        return max(dp1.back(), dp2.back());
    }
};
