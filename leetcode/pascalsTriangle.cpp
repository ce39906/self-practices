/*************************************************************************
    > File Name: pascalsTriangle.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-22 20:01:57
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
        {
            return {};
        }
        
        if (numRows == 1)
        {
            return {{1}};
        }
        
        vector<vector<int>> res = generate(numRows - 1);
        vector<int> cur_level;
        cur_level.reserve(numRows);
        cur_level.push_back(1);
        const vector<int>& last_level = res.back();
        for (int i = 0; i < last_level.size() - 1; i++)
        {
            cur_level.push_back(last_level[i] + last_level[i + 1]);
        }
        cur_level.push_back(1);
        res.emplace_back(cur_level);
        return res;
    }
};
