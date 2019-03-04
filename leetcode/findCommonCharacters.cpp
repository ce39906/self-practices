/*************************************************************************
    > File Name: findCommonCharacters.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-04 17:44:53
 ************************************************************************/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<unordered_map<int, int>> dict(26);
        const int n = A.size();
        for (int i = 0; i < n; i++)
        {
            for (const auto c : A[i])
            {
                dict[c - 'a'][i]++;
            }
        }
        
        vector<string> res;
        for (int i = 0; i < 26; i++)
        {
            const unordered_map<int, int>& freqs = dict.at(i);
            if (freqs.size() != n)
            {
                continue;
            }
            
            
            int min_freq = INT_MAX;
            for (auto it = freqs.cbegin(); it != freqs.cend(); ++it)
            {
                min_freq = min(min_freq, it->second);   
            }
            
            for (int j = 0; j < min_freq; j++)
            {
                res.emplace_back(1, 'a' + i);
            }
        }
        
        return res;
    }
};
