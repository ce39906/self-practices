/*************************************************************************
    > File Name: lengthOfLongestSubstring.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-10 15:30:27
 ************************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2)
        {
            return s.size();
        }
        vector<int> ascii_dict(256, -1);
        int start = 0;
        int res = 1;
        for (int i = 0; i < s.size(); i++)
        {
            const unsigned index = (unsigned)(s[i]);
            if (ascii_dict[index] >= start)
            {
                res = max(res, i - start);
                start = ascii_dict[index] + 1;
            }
            ascii_dict[index] = i;
        }
        res = max(res, int(s.size() - start));
        return res;
    }
};
