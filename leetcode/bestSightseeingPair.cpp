/*************************************************************************
    > File Name: bestSightseeingPair.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-27 16:01:31
 ************************************************************************/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        const int n = A.size();
        vector<int> plus(n);
        vector<int> minus(n);
        for (int i = 0; i < n; i++)
        {
            plus[i] = A[i] + i;
            minus[i] = A[i] - i;
        }
        
        vector<int> right_maxs(n);
        right_maxs[n - 1] = minus[n - 1];
        int cur_max = minus[n - 1];
        for (int i = n - 2; i > 0; i--)
        {
            cur_max = max(cur_max, minus[i]);
            right_maxs[i] = cur_max;
        }
        
        int res = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            res = max(plus[i] + right_maxs[i + 1], res);
        }

        return res;
    }
};
