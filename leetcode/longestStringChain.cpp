/*************************************************************************
    > File Name: longestStringChain.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-10 16:05:57
 ************************************************************************/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int, set<string>> len_2_words;
        for (const string& word : words)
        {
            const int n = word.size();
            if (len_2_words.count(n))
            {
                len_2_words[n].insert(word);
            }
            else
            {
                len_2_words[n] = {word};
            }
        }

        int res = 1;
        for (const string& word : words)
        {
            dfs(word, len_2_words, 1, res);
        }

        return res;
    }

private:
    void dfs(const string& word,
             const unordered_map<int, set<string>>& len_2_words,
             int len,
             int& res)
    {
        res = max(res, len);
        int size = word.size();
        if (!len_2_words.count(size + 1))
        {
            return;
        }

        const set<string>& nexts = len_2_words.at(size + 1);
        for (const string& next : nexts)
        {
            if (!chain(word, next))
            {
                continue;
            }
            dfs(next, len_2_words, len + 1, res);
        }
    }

    bool chain(const string& word,
               const string& next)
    {
        vector<int> table(26, 0);
        for (const char c : next)
        {
            table[c - 'a']++;
        }

        for (const char c : word)
        {
            table[c - 'a']--;
        }
        
        int zeros = 0;
        int ones = 0;
        for (const int val : table)
        {
            if (val == 0)
            {
                zeros++;
            }
            else if (val == 1)
            {
                ones++;
            }
            else
            {
                return false;
            }
        }

        return ones == 1;
    }
};
