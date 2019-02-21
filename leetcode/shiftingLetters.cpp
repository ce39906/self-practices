/*************************************************************************
    > File Name: shiftingLetters.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-18 14:41:00
 ************************************************************************/
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for (int i = shifts.size() - 1; i >= 0; i--)
        {
            shifts[i] %= 26;
            
            if (i == shifts.size() - 1)
            {
                continue;
            }
            
            shifts[i] += shifts[i + 1]; 
        }
        
        for (int i = 0; i < S.size(); i++)
        {
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        
        return S;
    }
};
