/*************************************************************************
    > File Name: containsDuplicateIII.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-22 10:22:29
 ************************************************************************/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (   nums.empty()
            || k == 0
            || t < 0)
        {
            return false;
        }

        set<int> window;
        int i = 0;
        // init window
        while (i <= k && i < nums.size())
        {
            if (window.count(nums[i]))
            {
                return true;
            }
            window.insert(nums[i]);
            i++;
        }
        // check the first window
        long last_num = (long)*window.begin();
        auto it = ++window.begin();
        for (; it != window.end(); ++it)
        {
            long cur_num = (long)(*it);
            if (cur_num - last_num <= t)
            {
                return true;
            }
            last_num = cur_num;
        }

        while (i < nums.size())
        {
            int pop_num = nums[i - k - 1];
            int push_num = nums[i];
            window.erase(pop_num);
            if (window.count(push_num))
            {
                return true;
            }

            if (pop_num != push_num)
            {
                int cur_max = *window.rbegin();
                int cur_min = *window.begin();
                auto it = window.insert(push_num).first;

                if (push_num > cur_max)
                {
                    if (push_num - cur_max <= t) return true;
                }
                else if (push_num < cur_min)
                {
                    if (cur_min - push_num <= t) return true;
                }
                else
                {
                    auto left_it = --it;
                    ++it;
                    auto right_it = ++it;
                    if (push_num - *left_it <= t || *right_it - push_num <= t)
                    {
                        return true;
                    }  
                }
            }
            i++;
        }

        return false;
    }
};
