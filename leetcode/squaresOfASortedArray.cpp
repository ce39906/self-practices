/*************************************************************************
    > File Name: squaresOfASortedArray.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-11 15:17:46
 ************************************************************************/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // bucket sort
        vector<int> bucket(10001, 0);
        for (const int a : A)
        {
            bucket[a > 0 ? a : -a]++;
        }

        vector<int> res;
        res.reserve(A.size());
        for (int i = 0; i < 10001; i++)
        {
            int count = bucket[i];
            while (count--)
            {
                res.push_back(i * i);
            }
        }

        return res;
    }
};
