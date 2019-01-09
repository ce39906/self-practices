/*************************************************************************
    > File Name: sortCharactersByFrequency.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-09 17:08:16
 ************************************************************************/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> char_2_count;
        for (const char c : s)
        {
            char_2_count[c]++;
        }
        
        vector<pair<int, char>> count_2_chars;
        for (auto cit = char_2_count.cbegin(); cit != char_2_count.cend(); ++cit)
        {
            count_2_chars.emplace_back((*cit).second, (*cit).first);
        }
        
        const auto cmp = [](const pair<int, char>& lhs, const pair<int, char>& rhs){
            return lhs.first > rhs.first;
        };
        
        sort(count_2_chars.begin(), count_2_chars.end(), cmp);
        
        string res;
        res.reserve(s.size());
        
        for (const pair<int, char>& count_2_char : count_2_chars)
        {
            res.append(count_2_char.first, count_2_char.second);
        }
        
        return res;
    }
};
