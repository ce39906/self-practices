/*************************************************************************
    > File Name: stringCompression.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-21 11:02:24
 ************************************************************************/
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty())
        {
            return 0;
        }
        
        const int n = chars.size();
        char cur = chars.front();
        int count = 1;
        vector<char> copy;
        copy.reserve(n);
        copy.push_back(cur);
        for (int i = 1; i < n; i++)
        {
            if (chars[i] == cur)
            {
                count++;
            }
            else
            {
                if (count > 1)
                {
                    for (const char c : to_string(count))
                    {
                        copy.push_back(c);
                    }
                }

                cur = chars[i];
                count = 1;
                copy.push_back(cur); 
            } 
        }
        // process the last group
        if (count > 1)
        {
            for (const char c : to_string(count))
            {
                copy.push_back(c);
            }
        }
        chars.swap(copy);
        return chars.size();
    }
};
