/*************************************************************************
    > File Name: bisicCalculatorII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-05 17:20:21
 ************************************************************************/
class Solution {
public:
    int calculate(string s) {
        if (s.empty())
        {
            return 0;
        }
        
        stack<int> st;
        int num = 0;
        char sign = '+';
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            const char c = s[i];
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            
            if (!isdigit(c) && c != ' ' || i == size - 1)
            {
                if (sign == '+')
                {
                    st.push(num);
                }
                else if (sign == '-')
                {
                    st.push(-num);
                }
                else if (sign == '*')
                {
                    const int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                else if (sign == '/')
                {
                    const int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                
                sign = c;
                num = 0;
            }
        }
        
        int res = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            res += top;
        }
        
        return res;
    }
};
