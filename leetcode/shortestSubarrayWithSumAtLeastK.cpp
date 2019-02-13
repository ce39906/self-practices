/*************************************************************************
    > File Name: shortestSubarrayWithSumAtLeastK.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-13 17:29:41
 ************************************************************************/
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        const int n = A.size();
        int res = n + 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (sum >= K)
            {
                res = min(res, i + 1);
            }
            
            while (pq.size() && sum - pq.top().first >= K)
            {
                const auto& top = pq.top();
                res = min(res, i - top.second);
                pq.pop();
            }
            
            pq.emplace(sum, i);
        }
        
        return res == n + 1 ? -1 : res;
    }
};
