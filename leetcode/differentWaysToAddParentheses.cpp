/*************************************************************************
    > File Name: differentWaysToAddParentheses.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-11 17:56:59
 ************************************************************************/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        const int size = input.size();
        for (int i = 0; i < size; i++)
        {
            const char c = input[i];
            if (isdigit(c))
            {
                continue;
            }
            
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            
            for (const int l : left)
            {
                for (const int r : right)
                {
                    if (c == '+')
                    {
                        res.push_back(l + r);
                    }
                    else if (c == '-')
                    {
                        res.push_back(l - r);
                    }
                    else
                    {
                        res.push_back(l * r);
                    }
                }
            }
        }
        
        if (res.empty())
        {
            res.push_back(stoi(input));    
        }
        return res;
    }
};
