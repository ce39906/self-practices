/*************************************************************************
    > File Name: rotateImage.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-23 15:02:34
 ************************************************************************/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (vector<int>& row : matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};
