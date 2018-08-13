/*************************************************************************
    > File Name: integerToRoman.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-13 15:12:56
 ************************************************************************/
class Solution {
public:
    string intToRoman(int num) {
        vector<int> key_nums = 
            {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman_strs = 
            {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string res;
        for (size_t i = 0; i < key_nums.size(); i++)
        {
            while (num >= key_nums[i])
            {
                res.append(roman_strs[i]);
                num -= key_nums[i];
            }
        }
        return res;
    }
};
