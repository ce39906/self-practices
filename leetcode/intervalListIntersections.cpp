/*************************************************************************
    > File Name: intervalListIntersections.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-14 11:09:07
 ************************************************************************/
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> res;
        int i = 0;
        int j = 0;
        while (i < A.size() && j < B.size())
        {
            if (A[i].end < B[j].start)
            {
                i++;
            }
            else if (B[j].end < A[i].start)
            {
                j++;
            }
            else
            {
                res.emplace_back(max(A[i].start, B[j].start), min(A[i].end, B[j].end));
                if (A[i].end < B[j].end)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }

        return res;
    }
};
