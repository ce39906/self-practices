/*************************************************************************
    > File Name: rangeSumQuery2DImmutable.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-17 14:59:57
 ************************************************************************/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        const int m = matrix.size();
        const int n = m == 0 ? 0 : matrix[0].size();
        vector<vector<int>> tmp(m + 1, vector<int>(n + 1, 0));
        sums.swap(tmp);
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                sums[i][j] = matrix[i - 1][j - 1] + sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] + sums[row1][col1] - sums[row2 + 1][col1] - sums[row1][col2 + 1];
    }
private:
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
