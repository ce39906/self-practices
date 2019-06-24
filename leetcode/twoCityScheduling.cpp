/*************************************************************************
    > File Name: twoCityScheduling.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-24 11:48:25
 ************************************************************************/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        const auto cmp = [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] - lhs[1] < rhs[0] - rhs[1];
        };
        int res = 0;
        sort(costs.begin(), costs.end(), cmp);
        const int n = costs.size();
        for (int i = 0; i < n / 2; i++)
        {
            res += costs[i][0];
            res += costs[i + n / 2][1];
        }

        return res;
    }
};
