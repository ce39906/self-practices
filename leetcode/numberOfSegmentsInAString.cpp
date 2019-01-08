/*************************************************************************
    > File Name: numberOfSegmentsInAString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-08 17:34:53
 ************************************************************************/
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string word;
        int res = 0;
        while (getline(ss, word, ' '))
        {
            if (word != "")
            {
                res++;
            }
        }
        
        return res;
    }
};
