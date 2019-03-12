/*************************************************************************
    > File Name: rottingOranges.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-06 19:44:16
 ************************************************************************/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int orange_count = 0;
        int res = -1;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<vector<int>> que;
        const int m = grid.size();
        const int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0)
                {
                    orange_count++;
                }
                
                if (grid[i][j] == 2)
                {
                    que.push({i, j});
                }
            }
        }
        
        while (!que.empty())
        {
            res++;
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                vector<int> front = que.front();
                orange_count--;
                que.pop();
                for (int j = 0; j < dirs.size(); j++)
                {
                    int row = front[0] + dirs[j][0];
                    int col = front[1] + dirs[j][1];
                    if (   row < 0 
                        || row >= m
                        || col < 0 
                        || col >= n
                        || grid[row][col] != 1)
                    {
                        continue;
                    }
                    
                    grid[row][col] = 2;
                    que.push({row, col});
                }
            }
        }
        
        if (orange_count == 0)
        {
            return max(res, 0);
        }
        
        return -1;
    }
};
