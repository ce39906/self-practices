/*************************************************************************
    > File Name: generateParenthesis.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-14 15:20:11
 ************************************************************************/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
        {
            return {};
        }
        
        if (n == 1)
        {
            return {"()"};
        }
        
        set<string> parenthesis_set;
        for (const string& str : generateParenthesis(n - 1))
        {
            for (size_t i = 0; i < str.size(); i++)
            {
                if (str[i] == ')')
                {
                    const string parenthesis = str.substr(0, i) + "()" + str.substr(i);
                    parenthesis_set.emplace(move(parenthesis));
                }
            }
        }
        
        string parenthesis;
        parenthesis.reserve(n << 1);
        while (n--)
        {
            parenthesis.append("()");
        }
        
        parenthesis_set.emplace(move(parenthesis));
        
        return vector<string>(parenthesis_set.begin(), parenthesis_set.end());
    }
};
