/*************************************************************************
    > File Name: availableCapturesForRook.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-12 14:30:30
 ************************************************************************/
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == 'R')
                {
                    return   cap(board, i, j, 0, 1)
                           + cap(board, i, j, 0, -1)
                           + cap(board, i, j, 1, 0)
                           + cap(board, i, j, -1, 0);
                }
            }
        }

        return 0;
    }
private:
    int cap(const vector<vector<char>>& board,
            int x,
            int y,
            int dx,
            int dy) const
    {
        while (   x >= 0 
               && x < board.size()
               && y >= 0
               && y < board[x].size()
               && board[x][y] != 'B')
        {
            if (board[x][y] == 'p')
            {
                return 1;
            }

            x += dx;
            y += dy;
        }

        return 0;
    }
};
