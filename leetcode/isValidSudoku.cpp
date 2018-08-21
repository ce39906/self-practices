/*************************************************************************
    > File Name: isValidSudoku.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-20 14:57:19
 ************************************************************************/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row_table(9, vector<bool>(9, false));
        vector<vector<bool>> col_table(9, vector<bool>(9, false));
        vector<vector<bool>> sub_boxs_table(9, vector<bool>(9, false));
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                
                int sub_box_idx = i / 3 * 3 + j / 3;
                const size_t num = board[i][j] - '1';
                if (   row_table[i][num]
                    || col_table[j][num]
                    || sub_boxs_table[sub_box_idx][num])
                {
                    return false;
                }
                
                row_table[i][num] = true;
                col_table[j][num] = true;
                sub_boxs_table[sub_box_idx][num] = true;
            }
        }
        
        return true;
    }
};
