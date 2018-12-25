/*************************************************************************
    > File Name: reverseVowelsOfAString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 16:35:26
 ************************************************************************/
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = 
            {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            while (!vowels.count(s[i]))
            {
                i++;
            }
            
            while (!vowels.count(s[j]))
            {
                j--;
            }
            
            if (i < j && vowels.count(s[i]) && vowels.count(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        
        return s;
    }
};
