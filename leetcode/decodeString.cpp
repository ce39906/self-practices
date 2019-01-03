/*************************************************************************
    > File Name: decodeString.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-03 16:28:56
 ************************************************************************/
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int i = 0;
        stack<int> nums;
        stack<string> strs;
        
        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                int count = 0;
                while (isdigit(s[i]))
                {
                    count = 10 * count + (s[i] - '0');
                    i++;
                }
                nums.push(count);
            }
            else if (s[i] == '[')
            {
                strs.push(res);
                res = "";
                i++;
            }
            else if (s[i] == ']')
            {
                int cnt = nums.top();
                nums.pop();
                string tmp = strs.top();
                while (cnt)
                {
                    tmp += res;
                    cnt--;
                }
                
                res = tmp;
                strs.pop();
                i++;
            }
            else
            {
                res += s[i];
                i++;
            }
        }
        
        return res;
    }
};
