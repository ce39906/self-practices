/*************************************************************************
    > File Name: validPerfectSquare.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 19:58:56
 ************************************************************************/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while(num > 0 )
        {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
