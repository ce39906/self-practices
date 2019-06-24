/*************************************************************************
    > File Name: matrixCellsInDistanceOrder.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-24 11:13:40
 ************************************************************************/
struct Cmp
{
    Cmp(int r0, int c0) : r0(r0), c0(c0)
    {
    }

    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const
    {
        int lr = lhs[0];
        int lc = lhs[1];
        int rr = rhs[0];
        int rc = rhs[1];
        return manhattanDistance(r0, c0, lr, lc) < manhattanDistance(r0, c0, rr, rc);
    }

    int manhattanDistance(int r0, int c0, int r, int c) const
    {
        return abs(r0 - r) + abs(c0 - c);
    }

    int r0;
    int c0;
};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        res.reserve(R * C);
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end(), Cmp(r0, c0));
        return res;        
    }
};

