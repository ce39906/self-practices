/*************************************************************************
    > File Name: setMatrixZeros.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-02 21:33:37
 ************************************************************************/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return;
        const int n = matrix[0].size();
        // first row and col store state
        bool first_row_has_zero = false;
        bool first_col_has_zero = false;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                    {
                        first_row_has_zero = true;
                    }
                    if (j == 0)
                    {
                        first_col_has_zero = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // first row
        if (first_row_has_zero)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
        // first col
        if (first_col_has_zero)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
