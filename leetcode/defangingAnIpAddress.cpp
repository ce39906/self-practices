/*************************************************************************
    > File Name: defangingAnIpAddress.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-09-05 14:44:58
 ************************************************************************/
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        stringstream ss(address);
        string token;
        while (getline(ss, token, '.'))
        {
            res += token;
            res += "[.]";
        }
        res = res.substr(0, res.size() - 3);
        return res;
    }
};
