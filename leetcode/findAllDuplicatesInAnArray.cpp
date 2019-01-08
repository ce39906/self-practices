/*************************************************************************
    > File Name: findAllDuplicatesInAnArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-08 19:55:32
 ************************************************************************/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
            {
                res.push_back(idx + 1);
            }
            else
            {
                nums[idx] = -nums[idx];   
            }
        }
        
        return res;
    }
};
