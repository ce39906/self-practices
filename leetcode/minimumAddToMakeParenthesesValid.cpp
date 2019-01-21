/*************************************************************************
    > File Name: minimumAddToMakeParenthesesValid.cpp
    > Author: carbon06
    > Mail: carbon06@163.com 
    > Created Time: 2019-01-21 22:28:39
 ************************************************************************/
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        for (const char c : S)
        {
            if (c == ')' && !s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        }
        
        return s.size();
    }
};
