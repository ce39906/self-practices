/*************************************************************************
    > File Name: randsomNote.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-02 16:34:05
 ************************************************************************/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> table(26, 0);
        for (const char c : magazine)
        {
            table[c - 'a']++;
        }
        
        for (const char c : ransomNote)
        {
            if (--table[c - 'a'] < 0)
            {
                return false;
            }
        }
        
        return true;
    }
};
