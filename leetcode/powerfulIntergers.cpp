/*************************************************************************
    > File Name: powerfulIntergers.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-10 16:03:51
 ************************************************************************/
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> nums;
        for (int i = 0; pow(x, i) < bound; i++)
        {
            for (int j = 0; pow(x, i) + pow(y, j) <= bound; j++)
            {
                nums.insert(pow(x, i) + pow(y, j));
                if (y == 1)
                {
                    break;
                }
            }
            
            if (x == 1)
            {
                break;
            }
        }
        
        vector<int> res;
        for (const auto& num : nums)
        {
            res.push_back(num);
        }
        
        return res;
    }
};
