/*************************************************************************
    > File Name: mostStonesRemovedWithSameRowOrColumn.cpp
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2019-01-15 22:27:59
 ************************************************************************/
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> cols;
        // build graph
        for(const auto& stone : stones)
        {
            const int row = stone[0];
            const int col = stone[1];
            if (rows.count(row))
            {
                rows[row].push_back(col);
            }
            else
            {
                rows[row] = {col};
            }
            
            if (cols.count(col))
            {
                cols[col].push_back(row);
            }
            else
            {
                cols[col] = {row};
            }
        }
        
        unordered_set<int> visited_rows;
        unordered_set<int> visited_cols;
        int islands = 0;
        for (const auto& stone : stones)
        {
            const int row = stone[0];
            const int col = stone[1];
            if (visited_rows.count(row))
            {
                continue;
            }
            
            islands++;
            dfsRows(rows, cols, row, visited_rows, visited_cols);
            dfsCols(rows, cols, col, visited_rows, visited_cols);
        }
        
        return stones.size() - islands;
    }
private:
    void dfsRows(const unordered_map<int, vector<int>>& rows,
                 const unordered_map<int, vector<int>>& cols,
                 const int row,
                 unordered_set<int>& visited_rows,
                 unordered_set<int>& visited_cols) const
    {
        if (visited_rows.count(row))
        {
            return;
        }
        
        visited_rows.insert(row);
    
        for (const int col : rows.at(row))
        {
            if (visited_cols.count(col))
            {
                continue;
            }
            dfsCols(rows, cols, col, visited_rows, visited_cols);
        }
    }
    
    void dfsCols(const unordered_map<int, vector<int>>& rows,
                 const unordered_map<int, vector<int>>& cols,
                 const int col,
                 unordered_set<int>& visited_rows,
                 unordered_set<int>& visited_cols) const
    {
        if (visited_cols.count(col))
        {
            return;
        }
        
        visited_cols.insert(col);
        for (const int row : cols.at(col))
        {
            if (visited_rows.count(row))
            {
                continue;
            }
            dfsRows(rows, cols, row, visited_rows, visited_cols);
        }
    }
   
};
