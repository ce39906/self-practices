/*************************************************************************
    > File Name: wordSearch.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-07 21:02:49
 ************************************************************************/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        if (!m) return false;
        const int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (search(board, word, 0, i, j, visited))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool search(const vector<vector<char>>& board,
                const string& word,
                const size_t cur,
                const int i,
                const int j,
                vector<vector<bool>>& visited) const
    {
        if (cur == word.size())
        {
            return true;
        }
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return false;
        }
        
        if (board[i][j] != word[cur] || visited[i][j])
        {
            return false;
        }
        
        visited[i][j] = true;
        const bool down_found = search(board, word, cur + 1, i + 1, j, visited);
        if (down_found)
        {
            visited[i][j] = false;
            return true;
        }
        const bool up_found = search(board, word, cur + 1, i - 1, j, visited);
        if (up_found)
        {
            visited[i][j] = false;
            return true;
        }
        const bool left_found = search(board, word, cur + 1, i, j - 1, visited);
        if (left_found)
        {
            visited[i][j] = false;
            return true;
        }
        const bool right_found = search(board, word, cur + 1, i, j + 1, visited);
        if (right_found)
        {
            visited[i][j] = false;
            return true;
        }
        
        visited[i][j] = false;
        
        return false;
    }
};
