/*************************************************************************
    > File Name: majorityElement.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-20 19:11:36
 ************************************************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int n = nums.size() / 2;
        unordered_map<int, int> num_2_count;
        for (const int num : nums)
        {
            if (++num_2_count[num] > n)
            {
                return num;
            }
        }
        return -1;
    }
};
