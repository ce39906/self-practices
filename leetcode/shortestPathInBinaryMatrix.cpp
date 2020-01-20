/*************************************************************************
    > File Name: shortestPathInBinaryMatrix.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2020-01-20 14:35:17
 ************************************************************************/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
        {
            return -1;
        }

        int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int, int>> que;
        int res = 0;
        que.push({0, 0});
        while (!que.empty())
        {
            int steps = que.size();
            res++;
            for (int i = 0; i < steps; i++)
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                if (x == n - 1 && y == n - 1)
                {
                    return res;
                }
                for (int j = 0; j < 8; j++)
                {
                    int x1 = x + d[j][0];
                    int y1 = y + d[j][1];
                    if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < n)
                    {
                        if (!grid[x1][y1])
                        {
                            que.push({x1, y1});
                            grid[x1][y1] = 1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};
