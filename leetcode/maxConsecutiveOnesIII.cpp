/*************************************************************************
    > File Name: maxConsecutiveOnesIII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-12 14:54:06
 ************************************************************************/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int zero_count = 0;
        int start = 0, res = 0;
        for (int end = 0; end < A.size(); end++)
        {
            if (A[end] == 0)
            {
                zero_count++;
            }

            while (zero_count > K)
            {
                if (A[start] == 0)
                {
                    zero_count--;
                }
                start++;
            }

            res = max(res, end - start + 1);
        }

        return res;
    }
};
