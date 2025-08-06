/*
Design a simplified version of Twitter where users can
- post tweets,
- follow/unfollow another user, and is
- able to see the 10 most recent tweets in the user's news feed.
*/

// u = number of users followed by userId (including themselves)
// t = average number of tweets per followed user (in tweets[user])
// Time Complexity:  O(u*t)
// tweets, followings,postTweet,follow, unfollow : O(1)
// getNewsFeed: users=u, tweets=t = O(u*t*log(10)) = O(u*t)

// Space complexity: O(10+t+f) =  O(T + F)
// tweets, followings  : O(t),O(f)
// minHeap : O(10)
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter
{
    // {userId, [tweets]}
    // tweet = {timestamp,tweetId}
    int timestamp = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    // {userid -> following}
    unordered_map<int, unordered_set<int>> followings;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        // Min-heap: {timestamp, tweetId}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;

        // posted by user themself.
        followings[userId].insert(userId);

        for (auto user : followings[userId])
        {
            // we can still optimize this by taking last 10 tweets from each
            // user
            for (auto tweet : tweets[user])
            {
                auto [timestamp, tweetId] = tweet;
                minHeap.push({timestamp, tweetId});
                if (minHeap.size() > 10)
                {
                    minHeap.pop();
                }
            }
        }

        vector<int> feed;
        while (!minHeap.empty())
        {
            feed.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(feed.begin(), feed.end());
        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        followings[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followings[followerId].erase(followeeId);
    }
};