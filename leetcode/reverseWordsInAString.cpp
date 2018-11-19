/*************************************************************************
    > File Name: reverseWordsInAString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-16 15:28:44
 ************************************************************************/
class Solution {
public:
    void reverseWords(string &s) {
        string word;
        vector<string> words;
        istringstream ss(s);
        while (getline(ss, word, ' '))
        {
            if (!word.empty())
            {
                words.push_back(word);
            }
        }
        
        s.clear();
        for (int i = words.size() - 1; i >= 0; i--)
        {
            s += words[i];
            if (i != 0)
            {
                s += " ";
            }
        }
    }
};
