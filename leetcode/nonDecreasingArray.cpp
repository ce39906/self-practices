/*************************************************************************
    > File Name: nonDecreasingArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-20 19:12:32
 ************************************************************************/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt <= 1; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                cnt++;
                if (i - 2 < 0 || nums[i - 2] <= nums[i])
                {
                    nums[i - 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return cnt <= 1;
    }
};
