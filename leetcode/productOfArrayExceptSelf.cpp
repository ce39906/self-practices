/*************************************************************************
    > File Name: productOfArrayExceptSelf.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-06 17:42:52
 ************************************************************************/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> left_product(n, 1);
        vector<int> right_product(n, 1);
        for (int i = 1; i < n; i++)
        {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }
        
        for (int i = n - 2; i >= 0; i--)
        {
            right_product[i] = right_product[i + 1] * nums[i + 1];
        }
        
        for (int i = 0; i < n; i++)
        {
            nums[i] = left_product[i] * right_product[i];
        }
        
        return nums;
    }
};
