/*************************************************************************
    > File Name: reverseString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 16:27:30
 ************************************************************************/
class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        
        return s;
    }
};
