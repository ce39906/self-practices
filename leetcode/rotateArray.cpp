/*************************************************************************
    > File Name: rotateArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 14:38:50
 ************************************************************************/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
