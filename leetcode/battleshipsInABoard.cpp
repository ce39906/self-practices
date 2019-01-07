/*************************************************************************
    > File Name: battleshipsInABoard.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-07 16:56:53
 ************************************************************************/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (  board[i][j] == 'X'
                   && (i == 0 || board[i-1][j] != 'X')
                   && (j == 0 || board[i][j-1] != 'X'))
                {
                    count++;
                }
            }
        }
        return count;
    }
};
