/*************************************************************************
    > File Name: outOfBoundaryPaths.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-17 16:48:21
 ************************************************************************/
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> mem(m, vector<vector<int>>(n, vector<int>(N + 1, -1)));
        return (int) (dfs(m, n, N, i, j, mem) % mod);
    }
private:
    static const int mod = 1000000007;
    long dfs(const int m,
             const int n,
             int N,
             int i,
             int j,
             vector<vector<vector<int>>>& mem) const
    { 
        if (i < 0 || j < 0 || i >= m || j >= n)
        {
            return 1;
        }
        
        if (N == 0)
        {
            return 0;
        }

        if (mem[i][j][N] != -1)
        {
            return mem[i][j][N];
        }

        mem[i][j][N] = 0;
        long up = dfs(m, n, N - 1, i - 1, j, mem) % mod;
        long down = dfs(m, n, N - 1, i + 1, j, mem) % mod;
        long left = dfs(m, n, N - 1, i, j - 1, mem) % mod;
        long right = dfs(m, n, N - 1, i, j + 1, mem) % mod;
        mem[i][j][N] = (mem[i][j][N] + up) % mod;
        mem[i][j][N] = (mem[i][j][N] + down) % mod;
        mem[i][j][N] = (mem[i][j][N] + left) % mod;
        mem[i][j][N] = (mem[i][j][N] + right) % mod;

        return mem[i][j][N];
    }
};
