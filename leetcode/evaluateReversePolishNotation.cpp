/*************************************************************************
    > File Name: evaluateReversePolishNotation.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-16 14:42:35
 ************************************************************************/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
        {
            return 0;
        }
        
        stack<int> s;
        for (const string& token : tokens)
        {
            if (token == "+")
            {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                int val = first + second;
                s.push(val);
            }
            else if (token == "-")
            {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                int val = second - first;
                s.push(val);
            }
            else if (token == "*")
            {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                int val = second * first;
                s.push(val);
            }
            else if (token == "/")
            {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                int val = second / first;
                s.push(val);
            }
            else
            {
                s.push(stoi(token));
            }
     
        }
        
        return s.top();
    }
};
