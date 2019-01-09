/*************************************************************************
    > File Name: repeatedSubstringPattern.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-09 19:11:02
 ************************************************************************/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) < s.size();
    }
};
