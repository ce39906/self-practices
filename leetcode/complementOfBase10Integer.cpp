/*************************************************************************
    > File Name: complementOfBase10Integer.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-20 20:02:45
 ************************************************************************/
class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int cnt = 0;
        int n = N;
        while (n)
        {
            n /= 2;
            cnt++;
        }
        return (1 << cnt) - 1 - N;
    }
};
