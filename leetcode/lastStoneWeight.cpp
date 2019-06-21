/*************************************************************************
    > File Name: lastStoneWeight.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-21 16:14:08
 ************************************************************************/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1)
        {
            const int first = pq.top();
            pq.pop();
            const int second = pq.top();
            pq.pop();
            if (first != second)
            {
                pq.push(first - second);
            }
        }
    
        return pq.empty() ? 0 : pq.top();
    }
};
