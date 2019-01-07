/*************************************************************************
    > File Name: thirdMaximumNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-04 15:16:24
 ************************************************************************/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq;
        unordered_set<int> unique_nums;
        for (const int num : nums)
        {
            if (unique_nums.count(num))
            {
                continue;
            }
            pq.push(num);
            unique_nums.insert(num);
        }
        
        if (pq.size() < 3)
        {
            return pq.top();
        }
        
        for (int i = 0; i < 2; i++)
        {
            pq.pop();
        }
        
        return pq.top();
    }
};
