/*************************************************************************
    > File Name: countingBits.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 15:57:19
 ************************************************************************/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        int i = 1;
        while (i <= num)
        {
            if ((i & i - 1) == 0)
            {
                res[i] = 1;
                int j = i + 1;
                for (; j < i * 2 && j <= num; j++)
                {
                    res[j] = res[j - i] + 1;
                }
                i = j;
            }
        }
        
        return res;
    }
};
