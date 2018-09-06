/*************************************************************************
    > File Name: minimumWindoSubstring.cpp
    > Author: ce33906
    > Mail: ce39906@163.com 
    > Created Time: 2018-09-06 22:19:27
 ************************************************************************/
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
        {
            return "";
        }
        int count = t.size();
        vector<int> m(128, 0);
        for (int i = 0; i < count; i++)
        {
            m[t[i]]++;
        }
        
        int left = 0;
        int right = 0;
        int length = INT_MAX;
        int head = -1;
        while (right < s.size())
        {
            if (m[s[right++]]-- > 0)
            {
                count--;
            }
            
            while (count == 0)
            {
                if (m[s[left++]]++ == 0)
                {
                    count++;
                }
                
                if (right - left + 1 < length)
                {
                    length = right - left + 1;
                    head = left - 1;
                }
            }
        }
        
        return head == -1 ? "" : s.substr(head, length);
    }
};
