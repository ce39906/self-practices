/*************************************************************************
    > File Name: findTheTownJudge.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-12 11:41:23
 ************************************************************************/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in_degree_minus_out_degree(N + 1, 0);
        for (const vector<int>& tru : trust)
        {
            const int from = tru.front();
            const int to = tru.back();
            in_degree_minus_out_degree[to]++;
            in_degree_minus_out_degree[from]--;
        }

        for (int i = 1; i <= N; i++)
        {
            if (in_degree_minus_out_degree[i] == N - 1)
            {
                return i;
            }
        }
        return -1;
    }
};
