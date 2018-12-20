/*************************************************************************
    > File Name: coinChange.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-18 17:51:36
 ************************************************************************/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int res = INT_MAX;
        dfs(coins, 0, amount, 0, res);
        
        return res == INT_MAX ? -1 : res;
    }
private:
    void dfs(const vector<int>& coins,
             int cur,
             int remind,
             int count,
             int& res) const
    {
        if (cur >= coins.size() || remind < 0)
        {
            return;
        }
       
        if (remind % coins[cur] == 0)
        {
            res = min(res, count + remind / coins[cur]);
        }
        
        for (int i = remind / coins[cur]; i >= 0; i--)
        {
            if (count + i + 1 > res)
            {
                break;
            }
            count += i;
            dfs(coins, cur + 1, remind - coins[cur] * i, count, res);
            count -= i;
        }
    }
};
