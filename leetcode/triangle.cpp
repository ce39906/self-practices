/*************************************************************************
    > File Name: triangle.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-23 19:42:56
 ************************************************************************/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j == 0)
                {
                    triangle[i][j] += triangle[i - 1][j];
                    continue;
                }
                
                if (j == triangle[i].size() - 1)
                {
                    triangle[i][j] += triangle[i - 1][j - 1];
                    continue;
                }
                
                triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }
        
        const auto& bottom = triangle.back();
        const auto min_it = std::min_element(bottom.begin(), bottom.end());
        return *min_it;
    }
};
