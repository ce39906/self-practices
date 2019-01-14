/*************************************************************************
    > File Name: maximumWidthRamp.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-11 11:33:03
 ************************************************************************/
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<pair<int, int>> num_and_idxs;
        for (int i = 0; i < A.size(); i++)
        {
            num_and_idxs.emplace_back(A[i], i);
        }
        
        sort(num_and_idxs.begin(), num_and_idxs.end());
        
        int res = 0;
        int cur_min_idx = INT_MAX;
        
        for (const auto& num_and_idx : num_and_idxs)
        {
            int idx = num_and_idx.second;
            res = max(res, idx - cur_min_idx);
            cur_min_idx = min(cur_min_idx, idx);
        }
        
        return res;
    }
};
