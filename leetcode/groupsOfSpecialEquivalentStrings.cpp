/*************************************************************************
    > File Name: groupsOfSpecialEquivalentStrings.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-18 14:57:32
 ************************************************************************/
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> groups;
        for (const string& a : A)
        {
            string odd_str = "";
            string even_str = "";
            for (int i = 0; i < a.size(); i++)
            {
                if (i % 2 != 0)
                {
                    odd_str.append(1, a[i]);
                }
                else
                {
                    even_str.append(1, a[i]);
                }
            }
            sort(odd_str.begin(), odd_str.end());
            sort(even_str.begin(), even_str.end());
            string group = odd_str + even_str;
            groups.insert(group);
        }
        return groups.size();
    }
};
