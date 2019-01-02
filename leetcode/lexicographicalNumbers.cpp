/*************************************************************************
    > File Name: lexicographicalNumbers.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-02 16:52:29
 ************************************************************************/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        res.reserve(n);
        dfs(1, 9, n, res);
        return res;
    }
private:
    void dfs(int start, int end, int n, vector<int>& res)
    {
        for (int i = start; i <= end && i <= n; i++)
        {
            res.push_back(i);
            dfs(i * 10, i * 10 + 9, n, res);
        }
    }
};
