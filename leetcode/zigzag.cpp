/*************************************************************************
    > File Name: zigzag.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-11 18:54:40
 ************************************************************************/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 0) return "";
        if (numRows == 1) return s;
        vector<string> zigzag_vec(numRows, "");
        size_t index = 0;
        bool increase_flag = true;
        for (char c : s)
        {   
            if (index == 0)
            {
                increase_flag = true;
            }
            
            if (index == numRows - 1)
            {
                increase_flag = false;
            }
            
            zigzag_vec[index].append(1, c);
            if (increase_flag)
            {
                index++;
            }
            else
            {
                index--;
            }
        }
        
        string res = accumulate(zigzag_vec.begin(), zigzag_vec.end(), string(""));
        return res;
    }
};
