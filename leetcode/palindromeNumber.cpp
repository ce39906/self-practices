/*************************************************************************
    > File Name: palindromeNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-11 22:02:49
 ************************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int low = 0;
        int high = str.size() - 1;
        while (low < high)
        {
            if (str[low++] != str[high--])
            {
                return false;
            }
        }
        return true;
    }
};
