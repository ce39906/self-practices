/*************************************************************************
    > File Name: letterTilePossibilities.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2020-01-15 17:00:22
 ************************************************************************/
class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<char> table(26, 0);
        for (const char c : tiles)
        {
            table[c - 'A']++;
        }
        int sum = 0;
        dfs(table, sum);
        return sum;
    }
private:
    void dfs(vector<char>& table, int& sum)
    {
        for (int i = 0; i < 26; i++)
        {
            if (table[i] == 0)
            {
                continue;
            }
            sum++;
            table[i]--;
            dfs(table, sum);
            table[i]++;
        }
    }
};
