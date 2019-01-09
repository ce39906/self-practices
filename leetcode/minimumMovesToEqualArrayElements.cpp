/*************************************************************************
    > File Name: minimumMovesToEqualArrayElements.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-09 17:14:57
 ************************************************************************/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = INT_MAX;
        int sum = 0;
        for(int num : nums)
        { 
            min_num = min(num, min_num);
            sum += num;
        }
        
        return sum - min_num * nums.size();
    }
};
