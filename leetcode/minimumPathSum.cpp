/*************************************************************************
    > File Name: minimumPathSum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-28 12:08:34
 ************************************************************************/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        for (int i = 1; i < m; i++)
        {
            grid[i][0] += grid[i - 1][0];
        }
        
        for (int j = 1; j < n; j++)
        {
            grid[0][j] += grid[0][j - 1];
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        return grid[m - 1][n - 1];
    }
};
