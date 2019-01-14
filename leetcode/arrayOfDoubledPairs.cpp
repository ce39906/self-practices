/*************************************************************************
    > File Name: arrayOfDoubledPairs.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-14 17:59:27
 ************************************************************************/
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        const int n = A.size();
        if (n == 0)
        {
            return true;
        }
        
        if (n & 1)
        {
            return false;
        }
        
        map<int, int> num_freqs;
        for (const int a : A)
        {
            num_freqs[a]++;
        }
        
        while (!num_freqs.empty())
        {
            const int num = num_freqs.begin()->first;
            int doubled = num << 1;
            if (num < 0 && num % 2 == 1)
            {
                return false;
            }
            
            if (num < 0)
            {
                doubled = num / 2;    
            }
            
            auto it = num_freqs.find(doubled);
            if (it == num_freqs.end())
            {
                return false;
            }
            
            if (--num_freqs.begin()->second == 0)
            {
                num_freqs.erase(num_freqs.begin());
            }
            
            if (--it->second == 0)
            {
                num_freqs.erase(it);
            }
        }
        
        return true;
        
    }
};
