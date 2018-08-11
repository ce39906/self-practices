/*************************************************************************
    > File Name: containerWithMostWater.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-11 23:08:25
 ************************************************************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            while (i < j && height[i] <= h)
            {
                i++;
            }
            while (i < j && height[j] <= h)
            {
                j--;
            }
        }
        return res;
    }
};
