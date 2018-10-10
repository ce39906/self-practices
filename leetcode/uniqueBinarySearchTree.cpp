/*************************************************************************
    > File Name: uniqueBinarySearchTree.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-10 17:54:33
 ************************************************************************/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
