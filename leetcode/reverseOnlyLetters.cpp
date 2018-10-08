/*************************************************************************
    > File Name: reverseOnlyLetters.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-08 12:01:00
 ************************************************************************/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        const int size = S.size();
        int i = 0;
        int j = size - 1;
        while (i < j)
        {
            while (!isalpha(S[i]))
            {
                i++;
            }
            while (!isalpha(S[j]))
            {
                j--;
            }
            
            if (i < j)
            {
                swap(S[i], S[j]);
                i++;
                j--;
            }
        }
        
        return S;
    }
};
