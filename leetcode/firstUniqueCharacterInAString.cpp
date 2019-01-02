/*************************************************************************
    > File Name: firstUniqueCharacterInAString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-02 16:55:52
 ************************************************************************/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> table(26, 0);
        for (const char c : s)
        {
            table[c - 'a']++;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (table[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};
