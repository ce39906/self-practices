/*************************************************************************
    > File Name: findKPairsWithSmallestSums.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-26 19:49:41
 ************************************************************************/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        struct Cmp{
            bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs)
            {
                return lhs.first + lhs.second > rhs.first + rhs.second;
            }
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                pq.push(std::make_pair(nums1[i], nums2[j]));
            }
        }
        
        vector<pair<int, int>> res;
        res.reserve(k);
        for (int i = 0; !pq.empty() && i < k; i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};
