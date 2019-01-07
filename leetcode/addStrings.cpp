/*************************************************************************
    > File Name: addStrings.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-04 15:17:26
 ************************************************************************/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res("");
        res.reserve(num1.size() +  num2.size() + 1);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int i = 0, j = 0,plus = 0;
        while(i < num1.size() && j < num2.size())
        {
            int x = num1[i++] - '0';
            int y = num2[j++] - '0';
            int sum = x + y + plus;
            if (sum >= 10)
            {
                sum -= 10;
                plus = 1;
            }else
            {
                plus = 0;
            }
            res += (sum + '0');
        }
        string& num = num1;
        size_t idx = i;
        if (j < num2.size())
        {
            num = num2;
            idx = j;
        }
        if (i < num.size())
        {
            string left = string(num.begin() + idx,num.end());
            if (plus == 1)
            {
                reverse(left.begin(),left.end());
                string left_res = addStrings(left,"1");
                reverse(res.begin(),res.end());
                return left_res + res;
            }
            reverse(res.begin(),res.end());
            reverse(left.begin(),left.end());
            return left + res;
        }
        reverse(res.begin(),res.end());
        if (plus == 1)
        {
            return "1" + res;
        }
        return res;
    }
};
