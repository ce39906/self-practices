/*************************************************************************
    > File Name: largestTimeForGivenDigits.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-15 16:00:23
 ************************************************************************/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        //permultation
        sort(A.begin(), A.end());
        string res = "";
        int mins = -1;
        do{
            int hour = 10 * A[0] + A[1];
            int min = 10 * A[2] + A[3];
            if (hour < 0 || hour >= 24)
            {
                continue;
            }
            if (min < 0 || min >= 60)
            {
                continue;
            }
            const int cur_mins = 60 * hour + min;
            if (cur_mins > mins)
            {
                mins = cur_mins;
                string hour_str = to_string(hour);
                string min_str = to_string(min);
                if (hour_str.size() == 1)
                {
                    hour_str = "0" + hour_str;
                }
                
                if (min_str.size() == 1)
                {
                    min_str = "0" + min_str;
                }

                res = hour_str + ":" + min_str;
            }
        } while (next_permutation(A.begin(), A.end()));

        return res;
    }
};
