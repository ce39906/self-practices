/*************************************************************************
    > File Name: solveSudoku.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-21 15:57:35
 ************************************************************************/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row_table(9, vector<bool>(9, false));
        vector<vector<bool>> col_table(9, vector<bool>(9, false));
        vector<vector<bool>> subboxs_table(9, vector<bool>(9, false));
        
        for (size_t i = 0; i < 9; i++)
        {
            for (size_t j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                const int num = board[i][j] - '1';
                row_table[i][num] = true;
                col_table[j][num] = true;
                const int subbox_idx = i / 3 * 3 + j / 3;
                subboxs_table[subbox_idx][num] = true;
            }
        }
        
        dfs(board, row_table, col_table, subboxs_table, 0, 0);
    }
    
private:
    
    bool dfs(vector<vector<char>>& board,
             vector<vector<bool>>& row_table,
             vector<vector<bool>>& col_table,
             vector<vector<bool>>& subboxs_table,
             int i,
             int j)
    {
        if (i == 9) return true;
        if (j == 9) return dfs(board, row_table, col_table, subboxs_table, i + 1, 0);
    
        if (board[i][j] == '.')
        {
            for (int k = 0; k < 9; k++)
            {
                const int subbox_idx = i / 3 * 3 + j / 3;
                if (row_table[i][k] || col_table[j][k] || subboxs_table[subbox_idx][k])
                {
                    continue;
                }
                        
                board[i][j] = k + '1';    
                row_table[i][k] = true;
                col_table[j][k] = true;
                subboxs_table[subbox_idx][k] = true;
                if (dfs(board, row_table, col_table, subboxs_table, i, j + 1))
                {
                    return true;
                }
                subboxs_table[subbox_idx][k] = false;
                col_table[j][k] = false;
                row_table[i][k] = false;
                board[i][j] = '.';
            }
            
            return false;
        }
        else
        {
            return dfs(board, row_table, col_table, subboxs_table, i, j + 1);
        }
    }
};
