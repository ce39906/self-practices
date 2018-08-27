/*************************************************************************
    > File Name: uniquePathsII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-27 19:58:26
 ************************************************************************/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
        {
            return 0;
        }
        
        obstacleGrid[0][0] = 1;
        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] || obstacleGrid[i - 1][0] == -1)
            {
                obstacleGrid[i][0] = -1;
                continue;
            }
            
            obstacleGrid[i][0] = 1;
        }
        
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[0][j] || obstacleGrid[0][j - 1] == -1)
            {
                obstacleGrid[0][j] = -1;
                continue;
            }
            
            obstacleGrid[0][j] = 1;
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j])
                {
                    obstacleGrid[i][j] = -1;
                }
                else
                {     
                    if (obstacleGrid[i - 1][j] != -1)
                    {
                        obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                    }
                    if (obstacleGrid[i][j - 1] != -1)
                    {
                        obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                    }
                }
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
};
