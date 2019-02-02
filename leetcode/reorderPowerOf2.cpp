/*************************************************************************
    > File Name: reorderPowerOf2.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-02 14:49:32
 ************************************************************************/
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string str_num = to_string(N);
        sort(str_num.begin(), str_num.end());
        do
        {
            if (str_num.front() == '0')
            {
                continue;
            }
            if (isPowerOf2(stoi(str_num)))
            {
                return true;
            }
        } while(next_permutation(str_num.begin(), str_num.end()));
        
        return false;
    }
private:
    bool isPowerOf2(const int num) const
    {
        return (num & num - 1) == 0;
    }
    
};
