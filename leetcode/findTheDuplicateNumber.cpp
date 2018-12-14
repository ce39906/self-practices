/*************************************************************************
    > File Name: findTheDuplicateNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-13 18:06:11
 ************************************************************************/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int n = nums.size();
        vector<bool> f(n, false);
        for (const int num : nums)
        {
            if (f[num])
            {
                return num;
            }
            f[num] = true;
        }
        
        return -1;
    }
};
