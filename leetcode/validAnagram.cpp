/*************************************************************************
    > File Name: validAnagram.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-11 18:57:40
 ************************************************************************/
class Solution {
public:
    bool isAnagram(string s, string t) {
        const auto get_char_table = [](const string& s){
            vector<int> char_table(26, 0);
            for (const char c : s)
            {
                char_table[c - 'a']++;
            }
            
            return char_table;
        };
        
        vector<int> table_s = get_char_table(s);
        vector<int> table_t = get_char_table(t);
        
        return table_s == table_t;
    }
};
