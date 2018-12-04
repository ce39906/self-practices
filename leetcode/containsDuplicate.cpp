/*************************************************************************
    > File Name: containsDuplicate.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-04 11:30:42
 ************************************************************************/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return !(s.size() == nums.size());
    }
};
