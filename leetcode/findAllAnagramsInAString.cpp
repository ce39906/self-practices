/*************************************************************************
    > File Name: findAllAnagramsInAString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-08 19:21:15
 ************************************************************************/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> s_table(26, 0);
        vector<int> p_table(26, 0);
        if (s.size() < p.size())
        {
            return {};
        }
        
        for (int i = 0; i < p.size(); i++)
        {
            s_table[s[i] - 'a']++;
            p_table[p[i] - 'a']++;
        }
        
        vector<int> res;
        if (s_table == p_table)
        {
            res.push_back(0);    
        }
        
        const int ps = p.size();
        for (int i = 1; i + ps - 1 < s.size(); i++)
        {
            s_table[s[i - 1] - 'a']--;
            s_table[s[i + ps - 1] - 'a']++;
            if (s_table == p_table)
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
