/*************************************************************************
    > File Name: integerReplacement.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-02 10:49:59
 ************************************************************************/
class Solution {
public:
    int integerReplacement(int n) {
        if (memory.count(n))
        {
            return memory[n];
        }

        if (n == 1)
        {
            memory[n] = 0;
            return 0;
        }

        if (n == INT_MAX)
        {
            memory[n] = 32;
            return 32;
        }

        int res;
        if (n % 2 == 0)
        {    
            res = 1 + integerReplacement(n / 2);
        }
        else
        {
            res = 1 + min(integerReplacement(n + 1), integerReplacement(n - 1));
        }

        memory[n] = res;
        return res;
    }
private:
    unordered_map<int, int> memory;
};
