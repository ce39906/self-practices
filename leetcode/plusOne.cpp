/*************************************************************************
    > File Name: plusOne.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-28 13:23:06
 ************************************************************************/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int sum;
            if (i == digits.size() - 1)
            {
                sum = digits[i] + 1 + carry;
            }
            else
            {
                sum = digits[i] + carry;
            }
            
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        
        if (carry)
        {
            digits.insert(digits.begin(), carry);    
        }
        
        return digits;
    }
};
