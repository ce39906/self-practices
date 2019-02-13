/*************************************************************************
    > File Name: scoreOfParentheses.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-13 19:36:04
 ************************************************************************/
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<char> s;
        int score = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == ')')
            {
                s.pop();
                int size = s.size();
                if (S[i - 1] == '(')
                {
                    score += (1 << size);
                }
            }
            else
            {
                s.push('(');
            }
        }
        return score;
    }
};
