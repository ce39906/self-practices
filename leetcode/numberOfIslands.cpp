/*************************************************************************
    > File Name: numberOfIslands.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 18:01:44
 ************************************************************************/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
        {
            return 0;
        }
        
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j])
                {
                    continue;
                }
                
                if (grid[i][j] == '0')
                {
                    visited[i][j] = 1;
                    continue;
                }
                // begin to bfs
                queue<pair<int, int>> que;
                que.push(std::make_pair(i, j));
                visited[i][j] = 1;
                res++;
                while (!que.empty())
                {
                    pair<int, int> front = que.front();
                    que.pop();
                    int row_idx = front.first;
                    int col_idx = front.second;
                    // left
                    if (col_idx > 0)
                    {
                        if (!visited[row_idx][col_idx - 1] && grid[row_idx][col_idx - 1] == '1')
                        {
                            que.push(std::make_pair(row_idx, col_idx - 1));
                        }
                        visited[row_idx][col_idx - 1] = 1;
                    }
                    // right
                    if (col_idx < n - 1)
                    {
                        if (!visited[row_idx][col_idx + 1] && grid[row_idx][col_idx + 1] == '1')
                        {
                            que.push(std::make_pair(row_idx, col_idx + 1));
                        }
                        visited[row_idx][col_idx + 1] = 1;
                    }
                    // down
                    if (row_idx < m - 1)
                    {
                        if (!visited[row_idx + 1][col_idx] && grid[row_idx + 1][col_idx] == '1')
                        {
                            que.push(std::make_pair(row_idx + 1, col_idx));
                        }
                        visited[row_idx + 1][col_idx] = 1;
                    }
                    // up
                    if (row_idx > 0)
                    {
                        if (!visited[row_idx - 1][col_idx] && grid[row_idx - 1][col_idx] == '1')
                        {
                            que.push(std::make_pair(row_idx - 1, col_idx));
                        }
                        visited[row_idx - 1][col_idx] = 1;
                    }
                }
                
            }
        }
        
        return res;
    }
};
