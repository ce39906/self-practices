/*************************************************************************
    > File Name: convertANumberToHexadcimal.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-03 19:43:59
 ************************************************************************/
class Solution {
public:
    string toHex(int num) {
        const char* table = "0123456789abcdef";
        unsigned int musk = 0xf;
        string res = "";
        if (num == 0)
        {
            return "0";
        }
        
        while (num && res.size() < 8)
        {
            res = table[num & musk] + res;
            num = num >> 4;
        }
        
        return res;
    }
};
