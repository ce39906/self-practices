/*************************************************************************
    > File Name: lengthOfLastWord.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-27 17:12:02
 ************************************************************************/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        // trim right
        int right = s.size() - 1;
        for (; right >= 0 && s[right] == ' '; right--)
        {
        }
        
        if (right < 0)
        {
            return 0;
        }
        
        for (int i = right; i >= 0 && s[i] != ' '; i--)
        {
            res++;
        }
        
        return res;
    }
};
