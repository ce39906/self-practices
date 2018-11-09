/*************************************************************************
    > File Name: singleNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-09 17:47:30
 ************************************************************************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::accumulate(nums.begin() + 1, nums.end(), nums.front(),
                              [](int a, int b){
                                  return a ^ b;
                              });
    }
};
