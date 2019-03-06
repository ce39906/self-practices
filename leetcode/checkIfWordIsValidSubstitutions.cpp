/*************************************************************************
    > File Name: checkIfWordIsValidSubstitutions.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-05 11:25:41
 ************************************************************************/
class Solution {
public:
    bool isValid(string S) {
        size_t pos = S.find("abc");
        while (pos != string::npos)
        {
            S = S.substr(0, pos) + S.substr(pos + 3);
            pos = S.find("abc");
        }
        
        return S.empty();
    }
};
