/*************************************************************************
    > File Name: occurrencesAfterBigram.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 14:49:54
 ************************************************************************/
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }
        vector<string> res;
        for (int i = 0; i < tokens.size() - 2; i++)
        {
            if (tokens[i] == first && tokens[i + 1] == second)
            {
                res.push_back(tokens[i + 2]);
            }
        }

        return res;
    }
};
