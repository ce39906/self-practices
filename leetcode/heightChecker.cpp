/*************************************************************************
    > File Name: heightChecker.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-21 16:46:02
 ************************************************************************/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> s(heights);
        int res = 0;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            res += s[i] != heights[i];
        }

        return res;
    }
};
