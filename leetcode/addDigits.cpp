/*************************************************************************
    > File Name: addDigits.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-11 19:16:14
 ************************************************************************/
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10)
        {
            int n = num;
            int new_num = 0;
            while (n)
            {
                new_num += n % 10;
                n /= 10;
            }
            num = new_num;
        }
        
        return num;
    }
};
