/*************************************************************************
    > File Name: isSubsequence.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-02 19:00:26
 ************************************************************************/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())
        {
            return true;
        }
        
        if (t.empty())
        {
            return false;
        }
        
        int pos = -1;
        for (int i = 0; i < s.size(); i++)
        {
            pos = t.find_first_of(s[i], pos + 1);
            if (pos == string::npos)
            {
                return false;
            }
        }
        
        return true;
    }
};
