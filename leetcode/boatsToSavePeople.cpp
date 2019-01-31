/*************************************************************************
    > File Name: boatsToSavePeople.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-29 11:04:31
 ************************************************************************/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int i = 0;
        int j = people.size() - 1;
        int res = 0;
        while (i <= j)
        {
            if (people[i] == limit)
            {
                i++;
                res++;
            }
            else if (people[j] + people[i] <= limit)
            {
                j--;
                i++;
                res++;
            }
            else
            {
                i++;
                res++;
            }
        }
        
        return res;
    }
};
