/*************************************************************************
    > File Name: jumpGame.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-24 15:19:29
 ************************************************************************/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        const int n = nums.size();
        for (int reach = 0; i < n && i <= reach; i++)
        {
            reach = max(reach, i + nums[i]);
        }
        
        return i == n;
    }
};
