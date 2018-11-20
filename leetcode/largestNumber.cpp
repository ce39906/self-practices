/*************************************************************************
    > File Name: largestNumber.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-20 20:07:42
 ************************************************************************/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num_strs;
        num_strs.reserve(nums.size());
        for (const int num : nums)
        {
            num_strs.push_back(to_string(num));
        }
        
        const auto cmp = [](const string& lhs, const string& rhs){
            string tmp = lhs + rhs;
            string tmp1 = rhs + lhs;
            return tmp > tmp1;
        };
        
        sort(num_strs.begin(), num_strs.end(), cmp);
        string res;
        // trim left zeros
        int i = 0;
        for (; i < num_strs.size(); i++)
        {
            if (num_strs[i] != "0")
            {
                break;
            }
        }
        
        if (i == num_strs.size())
        {
            i--;
        }
        
        for (int j = i; j < num_strs.size(); j++)
        {
            res += num_strs[j];
        }
        
        return res;
    }
};
