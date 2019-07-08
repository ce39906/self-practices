/*************************************************************************
    > File Name: sortAnArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-07-08 11:37:15
 ************************************************************************/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<pair<int, int>> buckets(50001);
        for (const int num : nums)
        {
            int idx = abs(num);
            if (num < 0)
            {
                buckets[idx].second++;
            }
            else
            {
                buckets[idx].first++;
            }
        }

        vector<int> res;
        res.reserve(nums.size());
        for (int i = buckets.size() - 1; i >= 0; i--)
        {
            while (buckets[i].second)
            {
                res.push_back(-i);
                buckets[i].second--;
            }
        }

        for (int i = 0; i < buckets.size(); i++)
        {
            while (buckets[i].first)
            {
                res.push_back(i);
                buckets[i].first--;
            }
        }

        return res;
    }
};
