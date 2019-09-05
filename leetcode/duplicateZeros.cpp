/*************************************************************************
    > File Name: duplicateZeros.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 14:16:30
 ************************************************************************/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int n = arr.size();
        for (int i = 0; i < n;)
        {
            if (arr[i] != 0)
            {
                i++;
                continue;
            }
            for (int j = n - 1; j > i + 1; j--)
            {
                arr[j] = arr[j - 1];
            }
            if (i + 1 < n)
            {
                arr[i + 1] = 0;
            }
            i += 2;
        }
    }
};
