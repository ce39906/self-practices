/*************************************************************************
    > File Name: spiralMatrix.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-23 20:00:35
 ************************************************************************/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
        {
            return {};
        }
        
        int row_first = 0;
        int row_last = matrix.size() - 1;
        int col_first = 0;
        int col_last = matrix[0].size() - 1;
        
        vector<int> res;
        res.reserve(matrix.size() * matrix[0].size());
        while (row_first <= row_last && col_first <= col_last)
        {
            // left
            for (int i = col_first; i <= col_last; i++)
            {
                res.push_back(matrix[row_first][i]);
            }
            row_first++;
            
            // down
            for (int i = row_first; i <= row_last; i++)
            {
                res.push_back(matrix[i][col_last]);
            }
            col_last--;
            
            // right
            if (row_first <= row_last)
            {
                for (int i = col_last; i >= col_first; i--)
                {
                    res.push_back(matrix[row_last][i]);
                }
            }
            row_last--;
            
            // up
            if (col_first <= col_last)
            {
                for (int i = row_last; i >= row_first; i--)
                {
                    res.push_back(matrix[i][col_first]);
                }
            }
            col_first++;
        }
        
        return res;
    }
};
