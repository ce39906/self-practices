/*************************************************************************
    > File Name: magicSquaresInGrid.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-19 11:14:13
 ************************************************************************/
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (m == 0)
        {
            return 0;
        }
        const int n = grid[0].size();
        int res = 0;
        for (int i = 0; i + 2 < m; i++)
        {
            for (int j = 0; j + 2 < n; j++)
            {
                if (   grid[i][j] > 9
                    || grid[i][j] == 0
                    || grid[i][j] + grid[i + 2][j + 2] != grid[i][j + 2] + grid[i + 2][j])
                {
                    continue;
                }

                int row1_sum = 0, row2_sum = 0, row3_sum = 0;
                int col1_sum = 0, col2_sum = 0, col3_sum = 0;
                bool valid = true;
                vector<int> visited(9, 0);
                for (int k = i; valid && k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        const int num = grid[k][l];
                        if (num > 9 || num == 0)
                        {
                            valid = false;
                            break;
                        }

                        if (visited[num - 1])
                        {
                            valid = false;
                            break;
                        }
                        visited[num - 1] = 1;
                        if (k == i)
                        {
                            row1_sum += num;
                        }
                        else if (k == i + 1)
                        {
                            row2_sum += num;
                        }
                        else
                        {
                            row3_sum += num;
                        }

                        if (l == j)
                        {
                            col1_sum += num;
                        }
                        else if (l == j + 1)
                        {
                            col2_sum += num;
                        }
                        else
                        {
                            col3_sum += num;
                        }
                    }
                }

                if (   valid 
                    && row1_sum == row2_sum
                    && row1_sum == row3_sum
                    && col1_sum == col2_sum
                    && col2_sum == col3_sum)
                {
                    res++;
                }
            }
        }

        return res;
    }
};
