/*************************************************************************
    > File Name: longestValidParentheses.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-17 16:46:31
 ************************************************************************/
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<size_t> stack;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else
            {
                if (!stack.empty())
                {
                    if (s[stack.top()] == '(')
                    {
                        stack.pop();
                    }
                    else
                    {
                        stack.push(i);
                    }
                }
                else
                {
                    stack.push(i);
                }
            }
        }
        
        if (stack.empty())
        {
            return s.size();    
        }
        
        int end = s.size();
        int start = 0;
        
        while (!stack.empty())
        {
            start = stack.top();
            stack.pop();
            res = max(res, end - start - 1);
            end = start;
        }
        
        res = max(res, start);
        return res;
    }
};
