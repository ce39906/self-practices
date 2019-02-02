/*************************************************************************
    > File Name: binaryGap.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-02-02 14:58:32
 ************************************************************************/
class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        int last_pos = -1;
        int pos = 0;
        while (N)
        {
            pos++;
            if (N & 1)
            {
                if (last_pos != -1)
                {
                    res = max(res, pos - last_pos);
                }
                
                last_pos = pos;
            }
            
            N >>= 1;
        }
        
        return res;
    }
};
