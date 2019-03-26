/*************************************************************************
    > File Name: wiggleSortII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-26 19:16:46
 ************************************************************************/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >=0; i--)
        {
            nums[i] = sorted[i & 1 ? k++ : j++];
        }
    }
};
