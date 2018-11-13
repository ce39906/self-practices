/*************************************************************************
    > File Name: wordBreakII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-12 17:21:45
 ************************************************************************/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty())
        {
            return {};
        }
        
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<string> res = wordBreak(s, word_set);
        return res;
    }
private: 
    vector<string> wordBreak(const string& s,
                             const unordered_set<string>& word_set)
    {
        // first check memory
        if (m.count(s))
        {
            return m.at(s);
        }
        
        vector<string> res;
        if (word_set.count(s))
        {
            res.push_back(s);
        }
        
        for (int i = 1; i < s.size(); i++)
        {
            string right = s.substr(i);
            if (word_set.count(right))
            {
                string left = s.substr(0, i);
                vector<string> left_res = wordBreak(left, word_set);
                if (left_res.empty())
                {
                    continue;
                }
                
                for (string& str : left_res)
                {
                    str += (" " + right);
                    res.push_back(str);
                }
            }
        }
        
        m[s] = res;
        return res;
    }
    
    unordered_map<string, vector<string>> m;
};
