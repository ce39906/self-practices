/*************************************************************************
    > File Name: sortArrayByParityII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-21 19:38:19
 ************************************************************************/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        const int n = A.size();
        int i = 0;
        int j = 1;
        while (i < n && j < n)
        {
            while(i < n && A[i] % 2 == 0)
            {
                i += 2;
            }
            
            while (j < n && A[j] % 2 == 1)
            {
                j += 2;
            }
            
            if (i < n && j < n)
            {
                swap(A[i], A[j]);
                i += 2;
                j += 2;
            }
            
        }
        
        return A;
    }
};
