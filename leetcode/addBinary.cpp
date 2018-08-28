/*************************************************************************
    > File Name: addBinary.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-28 19:05:44
 ************************************************************************/
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        if (a.empty())
        {
            return b;
        }
        
        if (b.empty())
        {
            return a;
        }
        
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }
            
            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }
            
            carry = sum / 2;
            res.append(1, sum % 2 + '0');
        }
        
        if (carry)
        {
            res.append(1, carry + '0');
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
