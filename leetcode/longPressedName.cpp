/*************************************************************************
    > File Name: longPressedName.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-21 17:05:48
 ************************************************************************/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        const int n = name.size();
        const int m = typed.size();
        if (n > m)
        {
            return false;
        }
        
        int i = 0;
        int j = 0;
        while (j < m)
        {
            if (name[i] == typed[j])
            {
                if (i != n - 1)
                {
                    i++;
                }
                j++;
            }
            else if (i > 0 && typed[j] == name[i - 1])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        
        return i == n - 1 && name[i] == typed.back();
    }
};
