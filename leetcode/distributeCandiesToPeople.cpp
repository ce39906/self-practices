/*************************************************************************
    > File Name: distributeCandiesToPeople.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 14:38:22
 ************************************************************************/
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        for (int assigned = 0; candies > 0; candies -= assigned)
        {
            res[assigned % num_people] += min(candies, assigned + 1);
            assigned++;
        }
        return res;
    }
};
