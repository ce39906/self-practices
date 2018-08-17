/*************************************************************************
    > File Name: divideTwoIntegers.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-16 11:37:05
 ************************************************************************/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if (   (dividend > 0 && divisor < 0)
            || (dividend < 0 && divisor > 0))
        {
            sign = -1;
        }
        
        long ldividend = abs(long(dividend));
        long ldivisor = abs(long(divisor));
        
        if (ldivisor == 0)
        {
            return INT_MAX;
        }
        
        if (ldividend == 0 || ldividend < ldivisor)
        {
            return 0;
        }
        
        const long lres = divide(ldividend, ldivisor);
        if (lres > INT_MAX)
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        else
        {
            return static_cast<int>(sign * lres);
        }
        
    }
private:
    long divide(long dividend, long divisor) const
    {
        if (dividend < divisor)
        {
            return 0;
        }
        
        long sum = divisor;
        long multiply = 1;
        // equal to multiply 2, 4, 8, 16...
        while (sum + sum <= dividend)
        {
            sum += sum;
            multiply += multiply;
        }
        
        return divide(dividend - sum, divisor) + multiply;
    }
};
