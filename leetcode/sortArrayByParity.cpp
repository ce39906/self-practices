/*************************************************************************
    > File Name: sortArrayByParity.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-08 19:14:07
 ************************************************************************/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        const int size = A.size();
        int i = 0;
        int j = size - 1;
        while (i < j)
        {
            while (A[i] % 2 == 0)
            {
                i++;
            }
            while (A[j] % 2 == 1)
            {
                j--;
            }
            if (i < j)
            {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        }
        return A;
    }
};
