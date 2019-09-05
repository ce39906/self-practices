/*************************************************************************
    > File Name: numberOfEquivalentDominoPairs.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 15:28:43
 ************************************************************************/
struct Item
{
    int x;
    int y;
    Item(int x, int y) : x(x), y(y)
    {
    }
    bool operator< (const Item& rhs) const
    {
        if (x < rhs.x)
        {
            return true;
        }
        else if (x == rhs.x)
        {
            return y < rhs.y;
        }
        return false;
    }
};

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<Item, int> domino_freqs;
        for (const auto& domino : dominoes)
        {
            int x = domino[0];
            int y = domino[1];
            if (x > y)
            {
                swap(x, y);
            }
            Item item(x, y);
            if (domino_freqs.count(item))
            {
                domino_freqs[item]++;
            }
            else
            {
                domino_freqs[item] = 1;
            }
        }
        int res = 0;
        for (auto it = domino_freqs.begin(); it != domino_freqs.end(); ++it)
        {
            int freq = it->second;
            if (freq == 1)
            {
                continue;
            }
            res += freq * (freq - 1) / 2;
        }
        return res;
    }
};
