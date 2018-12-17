/*************************************************************************
    > File Name: rangeSumQueryImmutable.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-17 14:23:52
 ************************************************************************/
class NumArray {
public:
    NumArray(vector<int> nums) {
        const int size = nums.size();
        sums.resize(size + 1, 0);
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
            sums[i + 1] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
