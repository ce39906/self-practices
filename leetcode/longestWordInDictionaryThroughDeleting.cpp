/*************************************************************************
    > File Name: longestWordInDictionaryThroughDeleting.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-05-05 17:52:58
 ************************************************************************/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        const auto cmp = [](const string& lhs, const string& rhs){
            if (lhs.size() > rhs.size())
            {
                return true;
            }

            if (lhs.size() == rhs.size())
            {
                return lhs < rhs;
            }

            return false;
        };

        sort(d.begin(), d.end(), cmp);
        for (const string& str : d)
        {
            if (wordMatch(s, str))
            {
                return str;
            }
        }

        return "";
    }
private:
    bool wordMatch(const string& s1, const string& s2) const
    {
        if (s2.empty())
            return true;
        int i = 0;
        int j = 0;
        int m = s1.size();
        int n = s2.size();
        if (m < n)
            return false;
        while (i < m && j < n)
        {
            if (s1[i] != s2[j])
            {
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }

        return j == n;
    }
};
