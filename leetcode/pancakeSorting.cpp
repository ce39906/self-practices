/*************************************************************************
    > File Name: pancakeSorting.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-10 16:50:01
 ************************************************************************/
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        vector<int> res;
        for (int i = n; i > 0; i--)
        {
            auto max_it = max_element(A.begin(), A.begin() + i);
            reverse(A.begin(), max_it + 1);
            reverse(A.begin(), A.begin() + i);
            res.push_back(max_it - A.begin() + 1);
            res.push_back(i);
        }
        
        return res;
    }
};
