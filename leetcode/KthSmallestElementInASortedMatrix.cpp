/*************************************************************************
    > File Name: KthSmallestElementInASortedMatrix.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-27 17:30:53
 ************************************************************************/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int cur_max = INT_MIN;
        int cur_count = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {   
            if (matrix[i][0] >= cur_max)
            {
                if (cur_count + matrix[0].size() < k)
                {
                    cur_max = matrix[i].back();
                    cur_count += matrix[i].size();
                }
                else
                {
                    return matrix[i][k - cur_count - 1];
                }
            }
            else
            {
                for (int j = 0; j < matrix[0].size(); ++j)
                {
                    if (cur_count == k)
                    {
                        return cur_max;
                    }
                    if (matrix[i][j] > cur_max)
                    {
                        cur_max = matrix[i][j];
                    }
                    cur_count++;
                }
            }
        }
        return 0;
    }
};
