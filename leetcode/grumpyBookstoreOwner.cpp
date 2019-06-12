/*************************************************************************
    > File Name: grumpyBookstoreOwner.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-10 12:06:17
 ************************************************************************/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        const int n = customers.size();
        int satisfy = 0;
        int window_max = 0;
        for (int i = 0, window_sum = 0; i < customers.size(); i++)
        {
            if (grumpy[i] == 0)
            {
                satisfy += customers[i];
            }
            else
            {
                window_sum += customers[i];
            }
            if (i >= X)
            {
                window_sum -= grumpy[i - X] * customers[i - X];
            }
            window_max = max(window_max, window_sum);
        }

        return satisfy + window_max;
    }
};
