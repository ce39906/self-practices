/*************************************************************************
    > File Name: pascalsTriangleII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-23 17:59:49
 ************************************************************************/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
        {
            return {1};
        }
 
        vector<int> res;
        res.reserve(rowIndex + 1);
        res.push_back(1);
        vector<int> last_level = getRow(rowIndex - 1);
        for (int i = 0; i < rowIndex - 1; i++)
        {
            res.push_back(last_level[i] + last_level[i + 1]);
        }
        res.push_back(1);
        
        return res;
    }
};
