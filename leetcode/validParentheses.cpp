/*************************************************************************
    > File Name: validParentheses.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-14 12:35:52
 ************************************************************************/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (const char c : s)
        {
            if (  c == '('
               || c == '['
               || c == '{')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                {
                    return false;
                }
                const char left = stack.top();
                stack.pop();
                if (  (left == '(' && c != ')')
                   || (left == '[' && c != ']')
                   || (left == '{' && c != '}'))
                {
                    return false;
                }
            }
        }
        
        return stack.empty();
    }
};
