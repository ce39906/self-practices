/*************************************************************************
    > File Name: greastCommonDivisorOfStrings.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 11:29:13
 ************************************************************************/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        int gcd_length = min(len1, len2);
        while (gcd_length > 0)
        {
            const string divisor = str1.substr(0, gcd_length);
            if (divisiable(str1, divisor) && divisiable(str2, divisor))
            {
                return divisor;
            }
            gcd_length--;
        }

        return "";
    }
private:
    bool divisiable(const string& str1, const string& str2)
    {
        if (str1.size() < str2.size())
        {
            return false;
        }
        const int len1 = str1.size();
        const int len2 = str2.size();
        if (len1 % len2 != 0)
        {
            return false;
        }

        return str1 == multiply_str(str2, len1 / len2);
    }
    string multiply_str(const string& raw, int mul)
    {
        string res = "";
        while (mul)
        {
            res += raw;
            mul--;
        }
        return res;
    }
};
