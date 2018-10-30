/*************************************************************************
    > File Name: validPalindrome.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-30 19:49:42
 ************************************************************************/
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            while (!isalnum(s[i]) && i < j)
            {
                i++;
            }
            
            while (!isalnum(s[j]) && i < j)
            {
                j--;
            }
            
            if (toupper(s[i]) != toupper(s[j]))
            {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};
