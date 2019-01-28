/*************************************************************************
    > File Name: uncommonWordsFromTwoSentences.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-28 19:56:29
 ************************************************************************/
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        stringstream ss (A + " " + B);
        unordered_map<string, int> word_2_count;
        string word;
        while (ss >> word)
        {
            word_2_count[word]++;
        }
        
        vector<string> res;
        for (const auto& w : word_2_count)
        {
            if (w.second == 1)
            {
                res.push_back(w.first);
            }
        }
        
        return res;
    }
};
