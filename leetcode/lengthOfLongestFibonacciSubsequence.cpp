/*************************************************************************
    > File Name: lengthOfLongestFibonacciSubsequence.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-25 15:10:10
 ************************************************************************/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                int a = A[i];
                int b = A[j];
                int l = 2;
                while (s.count(a + b))
                {
                    l++;
                    int sum = a + b;
                    a = max(a, b);
                    b = sum;
                }

                res = max(res, l);
            }
        }

        return res > 2 ? res : 0;
    }
};
