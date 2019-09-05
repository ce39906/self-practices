/*************************************************************************
    > File Name: findWordsThatCanBeFormedByCharacters.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 17:20:16
 ************************************************************************/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> char_table(26, 0);
        for (const auto c : chars)
        {
            char_table[c - 'a']++;
        }
        int res = 0;
        for (const auto& word : words)
        {
            if (wordFit(word, char_table))
            {
                res += word.size();
            }
        }

        return res;
    }

    bool wordFit(const string& word, const vector<int>& char_table)
    {
        vector<int> word_table(26, 0);
        for (const auto c : word)
        {
            word_table[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (word_table[i] > char_table[i])
            {
                return false;
            }
        }
        return true;
    }
};
