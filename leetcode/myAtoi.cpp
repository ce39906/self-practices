/*************************************************************************
    > File Name: myAtoi.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-11 21:54:21
 ************************************************************************/
class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int flag = 1;
        for (int i = 0; i < str.size();)
        {
            i = str.find_first_not_of(' ');
            if (str[i] == '-' || str[i] == '+')
            {
                flag = (str[i++] == '+' ? 1 : -1);
            }
            while(isdigit(str[i]))
            {
                res = res * 10 + (str[i++] - '0');
                if (res * flag >= INT_MAX) return INT_MAX;
                if (res * flag <= INT_MIN) return INT_MIN;
            }
            return res * flag;
        }
        return res * flag;
    }
};
