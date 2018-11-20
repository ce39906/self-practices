/*************************************************************************
    > File Name: excelSheetColumnTitle.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-20 15:38:59
 ************************************************************************/
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int r;
        if (n <= 0)
        {
            return res;
        }
        
        while (n)
        {
            r = (n - 1) % 26;
            res.insert(res.begin(), 'A' + r);
            n = (n - 1) / 26;
        }
        
        return res;
    }
};
