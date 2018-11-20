/*************************************************************************
    > File Name: excelSheetColumnNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-20 19:19:14
 ************************************************************************/
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int m = 1;
        for (int i = s.size() - 1; i >=0; i--)
        {
            int num = s[i] - 'A' + 1;
            res += num * m;
            m *= 26;
        }
        
        return res;
    }
};
