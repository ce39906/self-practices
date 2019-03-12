/*************************************************************************
    > File Name: sumOfEvenNumbersAfterQueries.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-11 14:34:13
 ************************************************************************/
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        res.reserve(A.size());
        int even_sum = accumulate(A.begin(), A.end(), 0, [](int lhs, int rhs){
            return rhs % 2 == 0 ? lhs + rhs : lhs;
        });
       
        for (const vector<int>& query : queries)
        {
            size_t idx = query[1];
            int num = query[0];
            if (A[idx] % 2 == 0)
            {
                if (num % 2 == 0)
                {
                    even_sum += num;
                }
                else
                {
                    even_sum -= A[idx];
                }
            }
            else
            {
                if (num % 2 != 0)
                {
                    even_sum += num + A[idx];
                }
            }

            A[idx] += num;
            res.push_back(even_sum);
        }

        return res;
    }
};
