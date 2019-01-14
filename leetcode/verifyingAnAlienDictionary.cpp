/*************************************************************************
    > File Name: verifyingAnAlienDictionary.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-14 19:16:57
 ************************************************************************/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dict;
        for (int i = 0; i < order.size(); i++)
        {
            dict[order[i]] = i;
        }
        
        for (int i = 1; i < words.size(); i++)
        {
            if (compare(words[i - 1], words[i], dict) > 0)
            {
                return false;
            }
        }
        
        return true;
    }
private:
    int compare(const string& lhs,
                const string& rhs,
                const unordered_map<char, int>& dict) const
    {
        const int m = lhs.size();
        const int n = rhs.size();
        for (int i = 0; i < m && i < n; i++)
        {
            int cmp = dict.at(lhs[i]) - dict.at(rhs[i]);
            if (cmp != 0)
            {
                return cmp;
            }
        }
        
        return m - n;
    }
};
