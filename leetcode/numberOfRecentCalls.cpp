/*************************************************************************
    > File Name: numberOfRecentCalls.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2019-03-15 17:52:23
 ************************************************************************/
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.insert(t);
        auto lit = pings.lower_bound(t - 3000);
        auto rit = pings.upper_bound(t);

        return distance(lit, rit);    
    }

private:
    set<int> pings;
};
