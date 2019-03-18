/*************************************************************************
    > File Name: smallestRangeI.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-18 14:59:06
 ************************************************************************/
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int max_num = A[0];
        int min_num = A[0];
        for (const int a : A)
        {
            max_num = max(max_num, a);
            min_num = min(min_num, a);
        }

        return max(0, max_num - min_num - 2 * K);
    }
};
