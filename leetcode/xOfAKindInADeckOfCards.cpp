/*************************************************************************
    > File Name: xOfAKindInADeckOfCards.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-08 14:31:50
 ************************************************************************/
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> table;
        for (const int num : deck)
        {
            table[num]++;
        }
        
        int res = 0;
        for (const auto it : table)
        {
            res = __gcd(res, it.second);
        }
        
        return res > 1;
    }
};
