/*************************************************************************
    > File Name: longestArithmeticSequence.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-04 11:42:26
 ************************************************************************/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if (A.size() < 2)
        {
            return A.size();
        }

        unordered_map<int, set<int>> inverted_idxs;
        for (int i = 0; i < A.size(); i++)
        {
            const int n = A[i];
            if (inverted_idxs.count(n))
            {
                inverted_idxs[n].insert(i);
            }
            else
            {
                inverted_idxs[n] = {i};
            }
        }

        int res = 2;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                int len = 2;
                int diff = A[j] - A[i];
                int next = A[j] + diff;
                int k = j;
                while(inverted_idxs.count(next))
                {
                    const set<int>& idxs = inverted_idxs.at(next);
                    auto it = idxs.upper_bound(k);
                    if (it == idxs.end())
                    {
                        break;
                    }
                    k = *it;
                    next = A[k] + diff;
                    len++;
                }
                res = max(res, len);
            }
        }

        return res;
    }
};
