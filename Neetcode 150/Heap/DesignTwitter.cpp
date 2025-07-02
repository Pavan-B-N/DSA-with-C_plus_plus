// https://leetcode.com/problems/design-twitter/
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
            // we can still optimize this by taking last 10 tweets from each user
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