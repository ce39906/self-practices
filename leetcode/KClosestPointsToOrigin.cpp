/*************************************************************************
    > File Name: KClosestPointsToOrigin.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-07 11:44:19
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] * lhs[0] + lhs[1] * lhs[1] < rhs[0] * rhs[0] + rhs[1] * rhs[1];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (const vector<int>& point : points)
        {
            if (pq.size() < K)
            {
                pq.push(point);
            }
            else
            {
                if (cmp(point, pq.top()))
                {
                    pq.pop();
                    pq.push(point);
                }
            }
        }
        
        vector<vector<int>> res(K);
        // pq is implemented by vector
        copy(&pq.top(), &pq.top() + K, res.begin());
        return res;
    }
};
