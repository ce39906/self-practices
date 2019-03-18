/*************************************************************************
    > File Name: reorderLogFiles.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-15 16:14:56
 ************************************************************************/
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        const auto cmp = [](const string& lhs, const string& rhs){
            int i = lhs.find(' ');
            int j = rhs.find(' ');
            if (!isdigit(lhs[i + 1]) && !isdigit(rhs[j + 1]))
            {
                return lhs.substr(i + 1) < rhs.substr(j + 1);
            }
            else
            {
                if (isdigit(lhs[i + 1]))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        };

        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};
