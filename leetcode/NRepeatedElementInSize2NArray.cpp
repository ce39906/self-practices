/*************************************************************************
    > File Name: NRepeatedElementInSize2NArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-11 11:59:34
 ************************************************************************/
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size() -  2; i++)
        {
            if (A[i] == A[i + 1] || A[i] == A[i + 2])
            {
                return A[i];
            }
        }
        
        return A.back();
    }
};
