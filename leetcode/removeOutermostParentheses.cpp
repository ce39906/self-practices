/*************************************************************************
    > File Name: removeOutermostParentheses.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-24 15:09:21
 ************************************************************************/
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        res.reserve(S.size());
        int opened = 0;
        for (const char c : S)
        {
            if (c == '(' && opened++ > 0)
            {
                res.append(1, c);
            }

            if (c == ')' && opened-- > 1)
            {
                res.append(1, c);
            }
        }

        return res;
    }
};
