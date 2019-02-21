/*************************************************************************
    > File Name: handOfStraights.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-21 19:54:03
 ************************************************************************/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        const int n = hand.size();
        if (n % W)
        {
            return false;
        }
        
        map<int, int> num_2_count;
        for (int num : hand)
        {
            num_2_count[num]++;
        }
        
        while (!num_2_count.empty())
        {
            if (num_2_count.size() < W)
            {
                return false;
            }
            
            int first = num_2_count.begin()->first;
            for (int i = first; i < first + W; i++)
            {
                if (!num_2_count.count(i))
                {
                    return false;
                }
                
                if (--num_2_count[i] == 0)
                {
                    num_2_count.erase(i);
                }
            }
        }
        
        return true;
    }
};
