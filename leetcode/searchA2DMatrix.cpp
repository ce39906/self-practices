/*************************************************************************
    > File Name: searchA2DMatrix.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-06 16:58:17
 ************************************************************************/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int>& target_row = matrix.front();
        for (const auto& row : matrix)
        {
            if (row.back() >= target)
            {
                target_row = row;
                break;
            }
        }
        
        // binary search
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low >> 1);
            if (target_row[mid] == target)
            {
                return true;
            }
            else if (target_row[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return false;
    }
};
