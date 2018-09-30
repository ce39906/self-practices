/*************************************************************************
    > File Name: wordSubsets.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-30 16:45:52
 ************************************************************************/
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        unordered_map<char, int> char_2_count;
        for (const string& str : B)
        {
            unordered_map<char, int> tmp_map;
            for (const char c : str)
            {
                tmp_map[c]++;
            }
            
            for (auto it = tmp_map.begin(); it != tmp_map.end(); ++it)
            {
                if (char_2_count.count(it->first))
                {
                    int last_count = char_2_count[it->first];
                    char_2_count[it->first] = max(last_count, it->second);
                }
                else
                {
                    char_2_count[it->first] = it->second;
                }
            }
        }
        
        vector<string> res;
        res.reserve(A.size());
        for (const string& str : A)
        {
            vector<int> char_table(26, 0);
            for (const char c : str)
            {
                char_table[c - 'a']++;
            }
            
            bool valid = true;
            for (auto it = char_2_count.begin(); it != char_2_count.end(); ++it)
            {
                if (char_table[it->first - 'a'] < it->second)
                {
                    valid = false;
                    break;
                }
            }
            
            if (valid)
            {
                res.push_back(str);
            }
        }
        
        return res;
    }
};
