/*************************************************************************
    > File Name: bestTimeToBuyAndSellStockII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-10-26 19:38:25
 ************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - prices[i - 1] > 0)
            {
                res += prices[i] - prices[i - 1];
            }
        }
        
        return res;
    }
};
