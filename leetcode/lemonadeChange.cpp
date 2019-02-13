/*************************************************************************
    > File Name: lemonadeChange.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-13 17:34:59
 ************************************************************************/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unsigned five_cash_cnt = 0;
        unsigned ten_cash_cnt = 0;
        
        for (const int bill : bills)
        {
            switch (bill)
            {
                case 5:
                    five_cash_cnt++;
                    break;
                case 10:
                    if (!five_cash_cnt)
                    {
                        return false;
                    }
                    five_cash_cnt--;
                    ten_cash_cnt++;
                    break;
                case 20:
                    if (ten_cash_cnt && five_cash_cnt)
                    {
                        ten_cash_cnt--;
                        five_cash_cnt--;
                    }
                    else if (five_cash_cnt > 2)
                    {
                        five_cash_cnt -= 3;
                    }
                    else
                    {
                        return false;
                    }
                    break;
            }
        }
        return true;
    }
};
