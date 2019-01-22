/*************************************************************************
    > File Name: findAndReplacePattern.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-22 19:57:59
 ************************************************************************/
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (const string& word : words)
        {
            if (match(word, pattern))
            {
                res.emplace_back(std::move(word));
            }
        }
        
        return res;
    }
private:
    bool match(const string& word,
               const string& pattern) const
    {
        if (word.size() != pattern.size())
        {
            return false;
        }
        
        const int n = word.size();
        unordered_set<char> s(pattern.begin(), pattern.end());
        unordered_map<char, char> map;
        unordered_set<char> mapped;
        for (int i = 0; i < n; i++)
        {
            if (s.count(pattern[i]))
            {
                if (mapped.count(word[i]))
                {
                    return false;
                }
                mapped.insert(word[i]);
                map[pattern[i]] = word[i];
                s.erase(pattern[i]);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            char p = map[pattern[i]];
            if (p != word[i])
            {
                return false;
            }
            
        }
        
        return true;
    }
};
