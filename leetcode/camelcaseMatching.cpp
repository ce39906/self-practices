/*************************************************************************
    > File Name: camelcaseMatching.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-27 17:39:32
 ************************************************************************/
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        const int n = queries.size();
        vector<bool> res;
        res.reserve(n);
        for (const string& query : queries)
        {
            res.push_back(match(query, pattern));
        }

        return res;
    }
private:
    bool match(const string& query, const string& pattern) const
    {
        int i = 0;
        for (const char c : query)
        {
            if (i < pattern.size() && c == pattern[i])
            {
                i++;
            }
            else if (c < 'a')
            {
                return false;
            }
        }

        return i == pattern.size();
    }
};
