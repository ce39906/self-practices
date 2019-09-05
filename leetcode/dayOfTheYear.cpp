/*************************************************************************
    > File Name: dayOfTheYear.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 15:58:39
 ************************************************************************/
class Solution {
public:
    int dayOfYear(string date) {
        vector<int> months = {0, 31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};
    
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        for (int i = 1; i < month; i++)
        {
            day += months[i];
        }
        if (leapYear(year) && month > 2)
        {
            day++;
        }

        return day;
    }
private:
    bool leapYear(int year) const
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
};
