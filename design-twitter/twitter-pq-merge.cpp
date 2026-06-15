#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter {
public:
  // Global chronological counter to assign unique logical time to each tweet
  int timer;

  // Maps followerId -> set of followeeIds to keep track of follow relationships
  unordered_map<int, unordered_set<int>> following;

  // Maps userId -> list of pair<timer, tweetId> representing user's tweets chronologically
  unordered_map<int, vector<pair<int, int>>> tweets;

  // Constructor initializes global timer to 0
  Twitter() { timer = 0; }

  // Posts a new tweet by appending {timer, tweetId} to the user's tweet vector and incrementing the timer
  void postTweet(int userId, int tweetId) {
    tweets[userId].push_back({timer++, tweetId});
  }

  // Follower starts following followeeId by inserting it into their following set
  void follow(int followerId, int followeeId) {
    following[followerId].insert(followeeId);
  }

  // Follower stops following followeeId (guarding against self-unfollow) by erasing it from the set
  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;

    following[followerId].erase(followeeId);
  }

  // Retrieves the 10 most recent tweet IDs across the user's own timeline and their followees' timelines
  vector<int> getNewsFeed(int userId) {

    // Max-heap to sort all gathered tweets by their timestamp (timer value) in descending order
    priority_queue<pair<int, int>> pq;

    // 1. Gather all tweets posted by the user themselves and push them to the heap
    for (auto &tweet : tweets[userId]) {
      pq.push(tweet);
    }

    // 2. Gather all tweets from everyone the user is following and push them to the heap
    for (int followee : following[userId]) {
      for (auto &tweet : tweets[followee]) {
        pq.push(tweet);
      }
    }

    // 3. Extract the 10 most recent tweet IDs (or fewer if less than 10 are available)
    vector<int> feed;

    while (!pq.empty() && feed.size() < 10) {
      feed.push_back(pq.top().second);
      pq.pop();
    }

    return feed;
  }
};