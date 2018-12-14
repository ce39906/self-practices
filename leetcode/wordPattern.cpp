/*************************************************************************
    > File Name: wordPattern.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-13 19:18:48
 ************************************************************************/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        stringstream ss(str);
        string word;
        while (getline(ss, word, ' '))
        {
            words.push_back(word);
        }
        
        if (pattern.size() != words.size())
        {
            return false;
        }
        
        unordered_set<string> unique_words;
        unordered_map<char, string> pattern_dict;
        for (int i = 0; i < pattern.size(); i++)
        {
            const char c = pattern[i];
            const string& word = words[i];
            unique_words.insert(word);
            if (pattern_dict.count(c))
            {
                if (word != pattern_dict[c])
                {
                    return false;
                }
            }
            else
            {
                pattern_dict[c] = word;
            }
        }
        
        return pattern_dict.size() == unique_words.size();
    }
};
