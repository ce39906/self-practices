/*************************************************************************
    > File Name: spiralMatrixII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-27 17:40:49
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n < 1)
            return {};
        vector<vector<int>> res(n, vector<int>(n));
        
        int row_begin = 0;
        int row_end = n - 1;
        int col_begin = 0;
        int col_end = n - 1;
        
        int num = 1;
        while (row_begin <= row_end && col_begin <= col_end)
        {
            // left
            for (int i = col_begin; i <= col_end; i++)
            {
                res[row_begin][i] = num++;
            }
            row_begin++;
            // down
            for (int i = row_begin; i <= row_end; i++)
            {
                res[i][col_end] = num++;
            }
            col_end--;
            // right
            if (col_begin <= col_end && col_begin <= col_end)
            {
                for (int i = col_end; i >= col_begin; i--)
                {
                    res[row_end][i] = num++;
                }
                row_end--;
                
                for (int i = row_end; i >= row_begin; i--)
                {
                    res[i][col_begin] = num++;
                }
                col_begin++;
            }
        }
        return res;
    }
};
