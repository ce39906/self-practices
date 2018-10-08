/*************************************************************************
    > File Name: partitionArrayIntoDisjointIntervals.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-08 17:34:58
 ************************************************************************/
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        const int size = A.size();
        vector<int> right_range_min;
        right_range_min.resize(size);
        int cur_min = A.back();
        right_range_min[size - 1] = cur_min; 
        for (int i = size - 2; i >= 1; i--)
        {
            cur_min = min(A[i], cur_min);
            right_range_min[i] = cur_min;
        }
        int i = 0;
        int cur_max = A[0];
        for (; i < size - 1; i++)
        {
            if (cur_max <= right_range_min[i + 1])
            {
                return i + 1;
            }
            cur_max = max(cur_max, A[i]);
        }
        
        return 1;
    }
};
