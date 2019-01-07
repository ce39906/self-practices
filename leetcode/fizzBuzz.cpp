/*************************************************************************
    > File Name: fizzBuzz.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-04 15:03:28
 ************************************************************************/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        res.reserve(n);
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                res.push_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                res.push_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                res.push_back("Buzz");
            }
            else 
            {
                res.push_back(to_string(i));
            }
        }
        
        return res;
    }
};
