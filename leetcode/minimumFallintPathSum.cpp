/*************************************************************************
    > File Name: minimumFallintPathSum.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-21 15:31:21
 ************************************************************************/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if (A.empty())
        {
            return 0;
        }
        
        const int n = A.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int added = A[i - 1][j];
                if (j >= 1)
                {
                    added = min(added, A[i - 1][j - 1]);
                }
                
                if (j < n - 1)
                {
                    added = min(added, A[i - 1][j + 1]);
                }
                
                A[i][j] += added;
            }
        }
        
        const vector<int>& bottom = A.back();
        return *min_element(bottom.begin(), bottom.end());
    }
};
