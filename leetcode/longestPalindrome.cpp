/*************************************************************************
    > File Name: longestPalindrome.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-10 17:26:35
 ************************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        if (n == 0) return "";
        int max_length = 1;
        int begin = 0;
        int end = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // i stands for substring begin , j stands for substring end
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                const bool last_state = i + 1 < n && j - 1 >= 0 && dp[i + 1][j - 1];
                if (s[i] == s[j] && (j - i < 3 || last_state))
                {
                    dp[i][j] = true;
                    if (j - i + 1 > max_length)
                    {
                        max_length = j - i + 1;
                        begin = i;
                        end = j;
                    }
                }
            }
        }
        
        return s.substr(begin, max_length);
    }
};
