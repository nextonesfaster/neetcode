// https://neetcode.io/problems/design-twitter-feed

#include <unordered_map>
#include <unordered_set>
#include <vector>

class Twitter {
  std::unordered_map<int, std::vector<std::pair<int, int>>> tweetsMap;
  std::unordered_map<int, std::unordered_set<int>> followingMap;
  int clock = 0;

public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    if (!tweetsMap.count(userId))
      tweetsMap.insert({userId, {}});
    tweetsMap[userId].push_back({tweetId, clock++});
  }

  // this is O(10n) where `n` is the number of users `userId` follows
  std::vector<int> getNewsFeed(int userId) {
    std::vector<int> feed;
    feed.reserve(10);
    follow(userId, userId);
    std::unordered_map<int, int> followee_indices;
    for (auto &followee : followingMap[userId])
      followee_indices[followee] = tweetsMap.count(followee) ? tweetsMap[followee].size() - 1 : -1;

    while (feed.size() < 10) {
      int max_time = -1, max_followee = -1, max_tweet = -1;
      for (auto &followee : followingMap[userId]) {
        if (followee_indices[followee] < 0)
          continue;

        int index = followee_indices[followee];
        auto [tweet, time] = tweetsMap[followee][index];

        if (max_time < time) {
          max_time = time;
          max_tweet = tweet;
          max_followee = followee;
        }
      }

      if (max_followee != -1)
        followee_indices[max_followee]--;
      else
        break;
      feed.push_back(max_tweet);
    }

    return feed;
  }

  void follow(int followerId, int followeeId) {
    if (!followingMap.count(followerId))
      followingMap.insert({followerId, {}});
    followingMap[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (followingMap.count(followerId))
      followingMap[followerId].erase(followeeId);
  }
};
