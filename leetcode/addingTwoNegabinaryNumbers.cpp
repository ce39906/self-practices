/*************************************************************************
    > File Name: addingTwoNegabinaryNumbers.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2020-01-15 17:01:43
 ************************************************************************/
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int carry = 0, i = arr1.size() - 1, j = arr2.size() - 1;
        while(i >= 0 || j >= 0 || carry)
        {
            if (i >= 0) carry += arr1[i--];
            if (j >= 0) carry += arr2[j--];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }

        while(res.size() > 1 && res.back() == 0)
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
