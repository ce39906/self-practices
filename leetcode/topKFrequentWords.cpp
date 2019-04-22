/*************************************************************************
    > File Name: topKFrequentWords.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-19 11:01:32
 ************************************************************************/
struct WordFreq
{
    WordFreq(int freq, string word) 
        : freq(freq), word(word)
    {
    }

    int freq;
    string word;

    bool operator < (const WordFreq& rhs) const
    {
        if (freq < rhs.freq)
        {
            return true;
        }

        if (freq == rhs.freq)
        {
            return word > rhs.word;
        }
        
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> word_freqs;
        for (const string word : words)
        {
            word_freqs[word]++;
        }
        
        priority_queue<WordFreq> pq;
        for (auto cit = word_freqs.cbegin(); cit != word_freqs.cend(); ++cit)
        {
            const string& word = cit->first;
            const int freq = cit->second;
            pq.emplace(freq, word);
        }

        vector<string> res;
        res.reserve(k);
        while (!pq.empty() && res.size() < k)
        {
            const WordFreq& top = pq.top();
            res.push_back(top.word);
            pq.pop();
        }

        return res;
    }
};
