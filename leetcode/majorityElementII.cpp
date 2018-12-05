/*************************************************************************
    > File Name: majorityElementII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-05 17:58:36
 ************************************************************************/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty())
        {
            return {};
        }
        
        int candidate_1 = nums.front();
        int candidate_2 = nums.front();
        int count_1 = 0;
        int count_2 = 0;
        for (const int num : nums)
        {
            if (num == candidate_1)
            {
                count_1++;
                continue;
            }
            if (num == candidate_2)
            {
                count_2++;
                continue;
            }
            
            if (count_1 == 0)
            {
                candidate_1 = num;
                count_1 = 1;
                continue;
            }
            
            if (count_2 == 0)
            {
                candidate_2 = num;
                count_2 = 1;
                continue;
            }
            
            count_1--;
            count_2--;
        }
        
        count_1 = 0;
        count_2 = 0;
        for (const int num : nums)
        {
            if (num == candidate_1)
            {
                count_1++;
            }
            else if (num == candidate_2)
            {
                count_2++;
            }
        }
        
        vector<int> res;
        if (count_1 > nums.size() / 3)
        {
            res.push_back(candidate_1);
        }
        
        if (count_2 > nums.size() / 3)
        {
            res.push_back(candidate_2);
        }
        
        return res;
    }
};
