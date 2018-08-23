/*************************************************************************
    > File Name: groupAnagrams.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-23 15:26:36
 ************************************************************************/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams_map;
        for (const string& str : strs)
        {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            if (anagrams_map.count(sorted_str))
            {
                anagrams_map[sorted_str].push_back(str);
            }
            else
            {
                anagrams_map[sorted_str] = vector<string>(1, str);
            }
        }
        
        vector<vector<string>> res;
        for (auto it = anagrams_map.begin(); it != anagrams_map.end(); ++it)
        {
            res.emplace_back(std::move(it->second));
        }
        
        return res;
    }
};
