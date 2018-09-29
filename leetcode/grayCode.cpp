/*************************************************************************
    > File Name: grayCode.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-29 20:02:18
 ************************************************************************/
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
        {
            return {0};
        }
       
        vector<int> res = grayCode(n - 1);
        int size = res.size();
        res.reserve(size << 1);
        for(int i = size - 1; i >= 0; i--)
        {
            res.push_back(res[i] | 1 << (n - 1));
        }
        
        return res;
    }
};
