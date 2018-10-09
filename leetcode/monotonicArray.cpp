/*************************************************************************
    > File Name: monotonicArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-08 19:55:11
 ************************************************************************/
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        const int size = A.size();
        if (size == 1)
        {
            return true;
        }
        int i = 0;
        int j = 1;
        while (j < size && A[j] == A[i])
        {
            j++;
        }
        
        if (j == size)
        {
            return true;
        }
        
        bool increase = true;
        if (A[j] < A[i])
        {
            increase = false;
        }
        
        while (j < size)
        {
            if (A[j] == A[j - 1])
            {
                j++;
                continue;
            }
            
            if (increase)
            {
                if (A[j] < A[j - 1])
                {
                    return false;
                }
            }
            else
            {
                if (A[j] > A[j - 1])
                {
                    return false;
                }
            }
            j++;
        }
        return true;
    }
};
