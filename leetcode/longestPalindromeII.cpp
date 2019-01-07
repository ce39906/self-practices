/*************************************************************************
    > File Name: longestPalindromeII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-04 14:59:27
 ************************************************************************/
class Solution {
public:
    int longestPalindrome(string s) {
        int alphabet_hash[58] = {0};
        for (auto c : s) alphabet_hash[c-'A']++;
        int cnt = 0;
        for (auto num: alphabet_hash)
        {
            if (num == 0) continue;
            cnt += num & 1 ? num - 1 : num; 
        }
        return cnt == s.size() ? s.size() : cnt + 1;
    }
};
