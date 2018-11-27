/*************************************************************************
    > File Name: isomorphicStrings.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-26 13:51:27
 ************************************************************************/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0};
        int m2[256] = {0};
        
        for (int i = 0; i < s.size(); i++)
        {
            if (m1[s[i]] != m2[t[i]])
            {
                return false;
            }
            
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        
        return true;
    }
};
