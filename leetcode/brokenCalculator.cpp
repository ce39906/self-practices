/*************************************************************************
    > File Name: brokenCalculator.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-12 15:27:31
 ************************************************************************/
class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y)
        {
            return X - Y;
        }

        if (X * 2 == Y)
        {
            return 1;
        }

        if (Y % 2 == 0)
        {
            return brokenCalc(X, Y / 2) + 1;
        }
        else
        {
            return brokenCalc(X, Y + 1) + 1;
        }
    }
};
