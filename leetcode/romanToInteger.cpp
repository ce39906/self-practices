/*************************************************************************
    > File Name: romanToInteger.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-13 15:24:53
 ************************************************************************/
class Solution {
public:
    int romanToInt(string s) {
        /*
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000
        */
        const unordered_map<char, int> m = 
            {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };
        
        int sum = m.at(s.back());
        for (int i = s.size() - 2; i >= 0; i--)
        {
            const int cur = m.at(s[i]);
            const int prev = m.at(s[i + 1]);
            if (cur < prev)
            {
                sum -= cur;
            }
            else
            {
                sum += cur;
            }
        }
        
        return sum;
    }
};
