/*************************************************************************
    > File Name: buddyStrings.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-13 17:49:29
 ************************************************************************/
class Solution {
public:
    bool buddyStrings(string A, string B) {
        const int n = A.size();
        const int m = B.size();
        if (n < 2 || m < 2 || m != n)
        {
            return false;
        }
        
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size())
        {
            return true;
        }
        
        vector<int> diff;
        for (int i = 0; i < n; i++)
        {
            if (A[i] != B[i])
            {
                diff.push_back(i);
            }
        }
        
        return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
};
