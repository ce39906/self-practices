/*************************************************************************
    > File Name: maximizeSumOfArrayAfterKNegations.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-15 14:47:49
 ************************************************************************/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i = 0;
        while (i < A.size() && A[i] <= 0 && K)
        {
            A[i] = -A[i];
            i++;
            K--;
        }
        
        sort(A.begin(), A.end());
        if (K % 2 == 1)
        {
            A[0] = -A[0];
        }
        
        return accumulate(A.begin(), A.end(), 0);
    }
};
