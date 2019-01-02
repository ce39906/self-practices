/*************************************************************************
    > File Name: findTheDifference.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-02 17:09:12
 ************************************************************************/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            res ^= (s[i] - 'a');
            res ^= (t[i] - 'a');
        }
        
        res ^= (t.back() - 'a');
        
        return res + 'a';
    }
};
