/*************************************************************************
    > File Name: searchInsertPosition.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-20 11:47:10
 ************************************************************************/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
