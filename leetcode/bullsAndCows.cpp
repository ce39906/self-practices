/*************************************************************************
    > File Name: bullsAndCows.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-17 11:55:32
 ************************************************************************/
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> table(10,0);
        for (int i = 0; i < secret.size(); i++)
        {
            const int s = secret[i];
            const int g = guess[i];
            if (s == g)
            {
                bulls++;
            }
            else
            {
                if (table[s - '0']++ < 0)
                {
                    cows++;
                }
                
                if (table[g - '0']-- > 0)
                {
                    cows++;    
                }
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
