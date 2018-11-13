/*************************************************************************
    > File Name: wordBreak.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-12 16:48:55
 ************************************************************************/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty())
        {
            return false;
        }
        
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        
        const int size = s.size();
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= size; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[j] && word_set.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp.back();
    }
};
