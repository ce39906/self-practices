/*************************************************************************
    > File Name: longestCommonPrefix.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-13 15:48:02
 ************************************************************************/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res("");
        if (strs.empty() || strs.front().empty())
        {
            return res;
        }
        
        const string& front = strs.front();
        for (size_t i = 0; i < front.size(); i++)
        {
            const char cur = front[i];
            for (size_t j = 1; j < strs.size(); j++)
            {
                const string& str = strs[j]; 
                if (i >= str.size() || str[i] != cur)
                {
                    return res;
                }
            }
            res.append(1, cur);
        }
        
        return res;
    }
};
