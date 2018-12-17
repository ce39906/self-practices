/*************************************************************************
    > File Name: rangeSumQueryMutable.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-17 16:46:42
 ************************************************************************/
class NumArray {
public:
    NumArray(vector<int> nums) {
        ori_nums = nums;
        const int n = nums.size();
        sums = vector<int>(n + 1, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sums[i + 1] = sum;
        }
    }
    
    void update(int i, int val) {
        int delta = val - ori_nums[i];
        ori_nums[i] = val;
        for (int j = i + 1; j < sums.size(); j++)
        {
            sums[j] += delta;
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
private:
    vector<int> ori_nums;
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
