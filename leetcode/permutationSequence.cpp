/*************************************************************************
    > File Name: permutationSequence.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-27 19:00:16
 ************************************************************************/
class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for (int i = 1; i <= n; i++)
        {
            str.append(1, i + '0');
        }
        
        int i = 1;
        while (i < k)
        {
            next_permutation(str.begin(), str.end());
            i++;
        }
        
        return str;
    }
};
