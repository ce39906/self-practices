/*************************************************************************
    > File Name: summaryRanges.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-05 17:43:40
 ************************************************************************/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int size = nums.size();
        vector<string> res;
        if (size == 0)
        {
            return res;
        }
        
        if (size == 1)
        {
            res.push_back(to_string(nums.front()));
            return res;
        }
        
        int first = 0;
        int j = 1;
        
        while (first < size && j < size)
        {
            if (nums[j] == nums[j - 1] + 1)
            {
                j++;
            }
            else
            {
                int last = j - 1;
                if (last == first)
                {
                    res.push_back(to_string(nums[first]));
                }
                else
                {
                    res.emplace_back(to_string(nums[first]) + "->" + to_string(nums[last]));
                }
                
                first = j;
                j += 1;
            }
        }
        
        int last = j - 1;
        if (last == first)
        {
            res.push_back(to_string(nums[first]));
        }
        else
        {
            res.emplace_back(to_string(nums[first]) + "->" + to_string(nums[last]));
        }
        
        return res;
    }
};
