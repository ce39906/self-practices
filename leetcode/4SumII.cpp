/*************************************************************************
    > File Name: 4SumII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-09 17:15:44
 ************************************************************************/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> A_plus_B(A.size() * A.size());
        unordered_map<int,int> C_plus_D(C.size() * C.size());
        
        const auto calculate_2_sum = [] (const vector<int>& vec1,
                                         const vector<int>& vec2,
                                         unordered_map<int,int>& plus)
        {
            for (const auto val1 : vec1)
            {
                for (const auto val2 : vec2)
                {
                    plus[val1 + val2]++;
                }
            }
        };
        
        calculate_2_sum(A, B, A_plus_B);
        calculate_2_sum(C, D, C_plus_D);
        
        int res = 0;
        for (const auto a_plus_b : A_plus_B)
        {
            if(C_plus_D.count(-a_plus_b.first))
            {
                res += a_plus_b.second * C_plus_D[-a_plus_b.first];
            }
        }
        return res;
    }
};
