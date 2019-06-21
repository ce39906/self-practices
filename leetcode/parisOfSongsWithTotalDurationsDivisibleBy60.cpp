/*************************************************************************
    > File Name: parisOfSongsWithTotalDurationsDivisibleBy60.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-21 15:37:59
 ************************************************************************/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> num_freqs;
        for (const int n : time)
        {
            num_freqs[n % 60]++;
        }

        int res = 0;
        for (auto cit = num_freqs.cbegin(); cit != num_freqs.cend(); ++cit)
        {
            const int num = cit->first;
            const int freqs = cit->second;
            const int left = 60 - num;
            if (num == left || num == 0)
            {
                res += freqs * (freqs - 1);
            }
            else
            {
                if (num_freqs.count(left))
                {
                    res += freqs * (num_freqs.at(left));
                }
            }
        }

        res >>= 1;
        return res;
    }
};
