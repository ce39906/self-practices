/*************************************************************************
    > File Name: happyNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-21 19:19:24
 ************************************************************************/
class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0)
        {
            return false;
        }
        
        unordered_set<int> visited;
        while (!visited.count(n))
        {
            int tmp = n;
            int squared_sum = 0;
            while (tmp)
            {
                int mod = tmp % 10;
                squared_sum += mod * mod;
                tmp /= 10;
            }
            
            if (squared_sum == 1)
            {
                return true;    
            }
            
            visited.insert(n);
            n = squared_sum;
        }
        
        return false;
    }
};
