/*************************************************************************
    > File Name: permutationInString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-04-10 16:24:40
 ************************************************************************/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2)
        {
            return false;
        }
        // init window
        vector<int> window(26, 0);
        for (int i = 0; i < len1; i++)
        {
            window[s1[i] - 'a']++;
            window[s2[i] - 'a']--;
        }

        if (allZero(window))
        {
            return true;
        }

        for (int i = len1; i < len2; i++)
        {
            window[s2[i - len1] - 'a']++;
            window[s2[i] - 'a']--;
            if (allZero(window))
            {
                return true;
            }
        }

        return false;
    }
private:
    bool allZero(const vector<int>& window) const
    {
        for (const int num : window)
        {
            if (num != 0)
            {
                return false;
            }
        }

        return true;
    }
};
