/*************************************************************************
    > File Name: longestSubstringWithAtLeastKRepeatingCharacters.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-03 17:01:30
 ************************************************************************/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return helper(s, 0, n - 1, k);
    }
private:
    int helper(const string& s, int l, int r, int k) const
    {
        vector<int> table(26, 0);
        for (int i = l; i <= r; i++)
        {
            table[s[i] - 'a']++;
        }
        
        bool pass = true;
        for (int i = 0; i < 26; i++)
        {
            if (table[i] && table[i] < k)
            {
                pass = false;
                break;
            }
        }
        
        if (pass)
        {
            return r - l + 1;
        }
        
        // divide str to 2 parts
        int res = 0;
        int i = l;
        for (int j = l; j <= r; j++)
        {
            if (table[s[j] - 'a'] && table[s[j] - 'a'] < k)
            {
                res = max(res, helper(s, i, j - 1, k));
                i = j + 1;
            }
        }
        
        res = max(res, helper(s, i, r, k));
        
        return res;
    }
};
