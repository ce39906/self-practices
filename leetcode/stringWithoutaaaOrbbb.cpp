/*************************************************************************
    > File Name: stringWithoutaaaOrbbb.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-11 15:06:45
 ************************************************************************/
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res;
        res.reserve(A + B);
        
        while (A || B)
        {
            const int n = res.size();
            if (A > B)
            {
                if (n >= 2 && res.substr(n - 2) == "aa")
                {
                    res.append(1, 'b');
                    B--;
                }
                else
                {
                    res.append(1, 'a');
                    A--;
                }
            }
            else
            {
                if (n >= 2 && res.substr(n - 2) == "bb")
                {
                    res.append(1, 'a');
                    A--;
                }
                else
                {
                    res.append(1, 'b');
                    B--;
                }
            }
        }
        
        return res;
    }
};
