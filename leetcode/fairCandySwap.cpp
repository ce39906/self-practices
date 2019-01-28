/*************************************************************************
    > File Name: fairCandySwap.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-28 15:37:46
 ************************************************************************/
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_a = 0;
        int sum_b = 0;
        unordered_set<int> s_a;
        for (const int a : A)
        {
            sum_a += a;
            s_a.insert(a);
        }
        
        for (const int b : B)
        {
            sum_b += b;
        }
        
        int diff = sum_a - sum_b >> 1;
        for (const int b : B)
        {
            if (s_a.count(b + diff))
            {
                return {b + diff, b};
            }
        }
        
        return {0, 0};
    }
};
