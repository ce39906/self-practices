/*************************************************************************
    > File Name: advantageShuffle.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-08 17:17:11
 ************************************************************************/
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(A.begin(), A.end());
        vector<int> res;
        for (const int num : B)
        {
            auto it = s.upper_bound(num);
            if (it == s.end())
            {
                res.push_back(*s.begin());
                s.erase(s.begin());
            }
            else
            {
                res.push_back(*it);
                s.erase(it);
            }
        }
        return res;
    }
};
