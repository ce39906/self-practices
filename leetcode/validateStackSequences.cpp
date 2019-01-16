/*************************************************************************
    > File Name: validateStackSequences.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-01-16 19:26:57
 ************************************************************************/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for (const int num : pushed)
        {
            s.push(num);
            while (!s.empty() && s.top() == popped[i])
            {
                i++;
                s.pop();
            }
        }
        
        return s.empty();
    }
};
