/*************************************************************************
    > File Name: reverseInteger.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-11 19:10:31
 ************************************************************************/
class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x < 0)
        {
            negative = true;
        }
        string x_str = to_string(x);
        std::reverse(x_str.begin(), x_str.end());
        // trim left zeros
        if (x_str != "0")
        {
            x_str.erase(0, x_str.find_first_not_of("0"));
        }
        
        long x_long = stol(x_str);
        if (negative)
        {
            x_long = -x_long;
        }
        // overflow?
        if (x_long < INT_MIN || x_long > INT_MAX)
        {
            return 0;
        }
        return static_cast<int>(x_long);
    }
};
