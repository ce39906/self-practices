/*************************************************************************
    > File Name: substringWithConcatenationOfAllWords.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-17 15:54:02
 ************************************************************************/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty())
        {
            return {};
        }
        
        vector<int> res;
        const int step = words.front().size();
        const int words_size = words.size() * step;
        const int str_size = s.size();
        
        unordered_map<string, int> word_count_map_const;
        for (const string& word : words)
        {
            word_count_map_const[word]++;
        }
        
        for (int i = 0; i <= str_size - words_size; i++)
        {
            unordered_map<string, int> word_count_map = word_count_map_const;    
            bool find = true;
            for (int j = i;  j < words_size + i; j += step)
            {
                const string word = s.substr(j, step);
                if (   !word_count_map.count(word)
                    || word_count_map[word] <= 0)
                {
                    find = false;
                    break;
                }
                
                word_count_map[word]--;               
            }
            
            if (find)
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
