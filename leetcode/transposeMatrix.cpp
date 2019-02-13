/*************************************************************************
    > File Name: transposeMatrix.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-13 17:04:18
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.empty())
        {
            return vector<vector<int>>{};
        }
        const size_t row_size = A.size();
        const size_t col_size = A[0].size();
        // guess to reduce cache miss
        const size_t block_size = 4;
        vector<vector<int>> res(col_size, vector<int>(row_size));
        for (size_t i = 0; i < row_size; i += block_size)
        {
            for (size_t j = 0; j < col_size; ++j)
            {
                for(size_t b = 0; b < block_size && i + b < row_size; ++b) 
                {
                    res[j][i + b] = A[i + b][j]; 
                }
            }
        }
        return res;
    }
};
