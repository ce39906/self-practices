/*************************************************************************
    > File Name: validTriangleNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-05-06 17:38:18
 ************************************************************************/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        const int n = nums.size();
        for (int i = n - 1; i >= 2; i--)
        {
            int l = 0;
            int r = i - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] > nums[i])
                {
                    res += r - l;
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }

        return res;
    }
};

