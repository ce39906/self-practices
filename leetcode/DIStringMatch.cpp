/*************************************************************************
    > File Name: DIStringMatch.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-18 12:02:25
 ************************************************************************/
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector<int> res;
        res.reserve(n + 1);
        int high =  n;
        int low = 0;
        for (const char c : S)
        {
            if (c == 'D')
            {
                res.push_back(high);
                high--;
            }
            else
            {
                res.push_back(low);
                low++;
            }
        }
        
        if (S.back() == 'D')
        {
            res.push_back(high);    
        }
        else
        {
            res.push_back(low);
        }
        return res;
    }
};
