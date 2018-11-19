/*************************************************************************
    > File Name: maximumGap.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-11-19 16:07:01
 ************************************************************************/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if (s.size() <= 1)
        {
            return 0;
        }
        
        int gap = 0;
        int last = *s.cbegin();
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (it == s.begin())
            {
                continue;
            }
            gap = max(gap, *it - last);
            last = *it;
        }
        return gap;
    }
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return 0;
        }

        int min_num = INT_MAX;
        int max_num = INT_MIN;

        for (const int num : nums)
        {
            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }

        const int size = nums.size();
        int min_gap = int(ceil((max_num - min_num) / float(size - 1)));

        vector<int> min_bucket(size - 1, INT_MAX);
        vector<int> max_bucket(size - 1, INT_MIN);
        for (const int num : nums)
        {
            if (num == min_num || num == max_num)
            {
                continue;
            }
            int idx = (num - min_num) / min_gap;
            min_bucket[idx] = min(min_bucket[idx], num);
            max_bucket[idx] = max(max_bucket[idx], num);
        }

        int gap = 0;
        int last = min_num;
        for (int i = 0; i < size - 1; i++)
        {
            if (min_bucket[i] == INT_MAX || max_bucket[i] == INT_MIN)
            {
                continue;
            }
            gap = max(gap, min_bucket[i] - last);
            last = max_bucket[i];
        }
        gap = max(gap, max_num - last);

        return gap;
    }
};
