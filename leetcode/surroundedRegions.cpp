/*************************************************************************
    > File Name: surroundedRegions.cpp
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2018-11-04 20:18:04
 ************************************************************************/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int row = board.size();
        if (row == 0)
        {
            return;
        }
        
        const int col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            // dfs from left
            dfsBoundary(board, row, col, i, 0);
            if (col > 1)
            {
                // dfs from right
                dfsBoundary(board, row, col, i, col - 1);
            }
        }
        
        for (int j = 1; j < col; j++)
        {
            // dfs from up
            dfsBoundary(board, row, col, 0, j);
            if (row > 1)
            {
                // dfs from down
                dfsBoundary(board, row, col, row - 1, j);
            }
        }
        // transform all O to X, all 1 to O
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '1')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfsBoundary(vector<vector<char>>& board,
                     const int row,
                     const int col,
                     int i,
                     int j) const
    {
        if (board[i][j] == 'O')
        {
            board[i][j] = '1';
            // up
            if (i > 1)
            {
                dfsBoundary(board, row, col, i - 1, j);
            }
            // right
            if (j > 1)
            {
                dfsBoundary(board, row, col, i, j - 1);
            }
            // down
            if (i + 1 < row)
            {
                dfsBoundary(board, row, col, i + 1, j);
            }
            // left
            if (j + 1 < col)
            {
                dfsBoundary(board, row, col, i, j + 1);
            }
        }
    }
};
