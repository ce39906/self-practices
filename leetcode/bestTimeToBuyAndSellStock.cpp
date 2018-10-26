/*************************************************************************
    > File Name: bestTimeToBuyAndSellStock.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-26 19:35:47
 ************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int cur = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            cur += prices[i] - prices[i - 1];
            cur = max(cur, 0);
            res = max(res, cur);
        }
        
        return res;
    }
};
