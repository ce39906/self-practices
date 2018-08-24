/*************************************************************************
    > File Name: insertInterval.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-08-24 16:02:37
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.emplace_back(newInterval.start, newInterval.end);
        
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
                || res.back().end < interval.start)
            {
                res.emplace_back(interval.start, interval.end);
            }
            else
            {
                res.back().end = max(res.back().end, interval.end);
            }
        }
        
        return res;
    }
};
