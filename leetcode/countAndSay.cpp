/*************************************************************************
    > File Name: countAndSay.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-21 19:25:28
 ************************************************************************/
class Solution {
public:
    string countAndSay(int n) {
        string res;
        if (n <= 0)
        {
            return res;
        }
        res = "1";
        
        while (--n)
        {
            string cur;
            for (size_t i = 0; i < res.size(); i++)
            {
                int count = 1;
                while (i + 1 < res.size() && res[i] == res[i + 1])
                {
                    count++;
                    i++;
                }
                cur += to_string(count);
                cur += res[i];
            }
            res = cur;
        }
        
        return res;
    }
};
