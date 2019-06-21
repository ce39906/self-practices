/*************************************************************************
    > File Name: removeAllAdjacentDuplicatesInString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-06-21 16:36:54
 ************************************************************************/
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        res.reserve(S.size());
        for (int i = 0; i < S.size();)
        {
            if (res.empty() || S[i] != res.back())
            {
                res.append(1, S[i]);
                i++;
            }
            else
            {
                int cnt = 1;
                while (i < S.size() && S[i] == res.back())
                {
                    cnt++;
                    i++;
                }
                if ((cnt & 1) == 0)
                {
                    res.pop_back();
                }
            }
        }

        return res;
    }
};
