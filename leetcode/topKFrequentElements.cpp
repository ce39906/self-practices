/*************************************************************************
    > File Name: topKFrequentElements.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 17:01:04
 ************************************************************************/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_2_frequency;
        for (const int num : nums)
        {
            num_2_frequency[num]++;
        }
        
        struct cmp
        {
            bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const
            {
                if (lhs.second < rhs.second)
                {
                    return true;
                }
                else if (lhs.second == rhs.second)
                {
                    return lhs.first < rhs.first;
                }
                else
                {
                    return false;
                }
            }
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto it = num_2_frequency.begin(); it != num_2_frequency.end(); ++it)
        {
            pq.push(*it);
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            int num = pq.top().first;
            res.push_back(num);
            pq.pop();
        }
        
        return res;
    }
};
