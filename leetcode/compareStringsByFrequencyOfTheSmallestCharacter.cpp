/*************************************************************************
    > File Name: compareStringsByFrequencyOfTheSmallestCharacter.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 17:40:57
 ************************************************************************/
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        multiset<int> freqs;
        for (const string& word : words)
        {
            freqs.insert(func(word));
        }
        vector<int> res;
        for (const string& query : queries)
        {
            int query_cnt = func(query);
            int cnt = std::distance(freqs.upper_bound(query_cnt), freqs.end());
            res.push_back(cnt);
        }

        return res;
    }
private:
    int func(const string& word) const
    {
        vector<char> char_table(26, 0);
        for (const char c : word)
        {
            char_table[c - 'a']++;
        }

        for (const int freq : char_table)
        {
            if (freq > 0)
            {
                return freq;
            }
        }

        return 0;
    }
};
