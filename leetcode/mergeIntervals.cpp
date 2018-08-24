/*************************************************************************
    > File Name: mergeIntervals.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-24 15:42:49
 ************************************************************************/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        struct Cmp
        {
            bool operator() (const Interval& lhs, const Interval& rhs) const
            {
                return lhs.start < rhs.start;
            }
        };

        sort(intervals.begin(), intervals.end(), Cmp());

        vector<Interval> res;
        res.reserve(intervals.size());

        for (const auto& interval : intervals)
        {
            if (   res.empty()
                || interval.start > res.back().end)
            {
                res.emplace_back(interval.start, interval.end);
            }
            else
            {
                Interval& back = res.back();
                back.end = max(interval.end, back.end);
            }
        }

        return res;
    }
};
