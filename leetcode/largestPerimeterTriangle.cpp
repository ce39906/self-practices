/*************************************************************************
    > File Name: largestPerimeterTriangle.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-11 15:32:29
 ************************************************************************/
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        const int n = A.size();
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                if (A[j] + A[j + 1] <= A[i])
                {
                    break;
                }
                for (int k = j + 1; k < n; k++)
                {
                    if (A[j] + A[k] > A[i])
                    {
                        return A[i] + A[j] + A[k];
                    }
                    else
                    {
                        break;
                    }
                    
                }
            }
        }

        return 0;
    }
};
