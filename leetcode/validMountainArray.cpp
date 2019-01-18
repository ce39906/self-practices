/*************************************************************************
    > File Name: validMountainArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-18 19:24:07
 ************************************************************************/
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        const int n = A.size();
        if (n < 3)
        {
            return false;
        }
        
        int i = 0;
        int j = n - 1;
        while (i < n - 1 && A[i] < A[i + 1])
        {
            i++;
        }
        
        while (j > 1 && A[j - 1] > A[j])
        {
            j--;
        }
        
        return i > 0 && j < n - 1 && i == j;
    }
};
