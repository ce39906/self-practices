/*************************************************************************
    > File Name: minimumIncrementToMakeArrayUnique.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-18 11:37:36
 ************************************************************************/
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        int need = 0;
        for (int a : A)
        {
            res += max(need - a, 0);
            need = max(need, a) + 1;
        }
        
        return res;
    }
};
