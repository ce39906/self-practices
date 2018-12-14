/*************************************************************************
    > File Name: moveZeros.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-13 17:53:01
 ************************************************************************/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last = 0, cur = 0;
        while(cur < nums.size())
        {
            if (nums[cur] != 0)
            {
                swap(nums[cur],nums[last]);
                last++;
            }
        }
    }
};
