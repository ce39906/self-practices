/*************************************************************************
    > File Name: designTwitter.cpp
    > Author: ce39906
    > Mail: ce39906@163.com 
    > Created Time: 2018-12-25 19:51:01
 ************************************************************************/
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        posts.push_back(std::make_pair(tweetId, userId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> follows;
        if (userId_2_follows.count(userId))
        {
            follows = userId_2_follows[userId];
        }
        
        vector<int> res;
        for (int i = posts.size() - 1; i >= 0; i--)
        {
            if (res.size() == 10)
            {
                return res;
            }
            
            int followId = posts[i].second;
            if (followId == userId || follows.count(followId))
            {
                res.push_back(posts[i].first);
            }
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (userId_2_follows.count(followerId))
        {
            userId_2_follows[followerId].insert(followeeId);
        }
        else
        {
            unordered_set<int> followees;
            followees.insert(followeeId);
            userId_2_follows[followerId] = followees;
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (userId_2_follows.count(followerId))
        {
            userId_2_follows[followerId].erase(followeeId);
        }
    }
private:
    unordered_map<int, unordered_set<int>> userId_2_follows;
    vector<pair<int, int>> posts;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
