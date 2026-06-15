# Design Twitter

**LeetCode #355** · [LeetCode](https://leetcode.com/problems/design-twitter/) · [NeetCode](https://neetcode.io/problems/design-twitter)

- **Difficulty:** Medium
- **Categories:** Hash Table, Linked List, Design, Heap, Priority Queue
- **Time Complexity:** `O(T log T)` for `getNewsFeed` (where `T` is the total tweets of user + followees), `O(1)` for other operations.
- **Space Complexity:** `O(U + T)` where `U` is the number of users and `T` is the number of total tweets.

---

## Problem Statement

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to retrieve the 10 most recent tweets in the user's news feed.

Implement the `Twitter` class:
- `Twitter()` Initializes your twitter object.
- `void postTweet(int userId, int tweetId)` Composes a new tweet with ID `tweetId` by the user `userId`. Each call to this function will be made with a unique `tweetId`.
- `List<Integer> getNewsFeed(int userId)` Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themselves. Tweets must be **ordered from most recent to least recent**.
- `void follow(int followerId, int followeeId)` The user with ID `followerId` starts following the user with ID `followeeId`.
- `void unfollow(int followerId, int followeeId)` The user with ID `followerId` starts unfollowing the user with ID `followeeId`.

---

## Intuition

To support post, follow, unfollow, and feed generation:
1. **Tweets Storage**: Each user's tweets must be stored sequentially. Since tweets are naturally posted chronologically, we can assign an incrementing global `timer` to each tweet, storing them in a `vector<pair<int, int>>` (timer, tweetId) per user.
2. **Follow Relationships**: We need to quickly know who a user is following. A map from `followerId` to an `unordered_set` of `followeeIds` allows `O(1)` insertions (follow), deletions (unfollow), and lookups.
3. **Feed Generation**: To fetch the 10 most recent tweets from the user and all their followees, we collect all their tweets and push them to a **max-heap (priority queue)** sorted by the timer. We then extract up to 10 most recent tweets from the heap.

---

## Approach

1. **Initialize structures**:
   - `timer`: initialized to `0`.
   - `following`: `unordered_map<int, unordered_set<int>>`.
   - `tweets`: `unordered_map<int, vector<pair<int, int>>>`.
2. **postTweet**: Append `{timer++, tweetId}` to `tweets[userId]`.
3. **follow / unfollow**: Insert or erase `followeeId` in `following[followerId]`. Guard against self-unfollowing in `unfollow`.
4. **getNewsFeed**: 
   - Push all of the user's tweets into the `priority_queue`.
   - Iterate through each followee of the user, pushing all of their tweets into the same `priority_queue`.
   - Pop and return the top 10 tweet IDs (most recent).

---

## Code

```cpp
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
```

---

## Complexity

| Method | Time Complexity | Space Complexity | Reason |
| :--- | :--- | :--- | :--- |
| `postTweet` | `O(1)` | `O(1)` | Appending to a vector takes amortized constant time. |
| `follow` | `O(1)` | `O(1)` | Inserting into an `unordered_set` takes constant time on average. |
| `unfollow` | `O(1)` | `O(1)` | Erasing from an `unordered_set` takes constant time on average. |
| `getNewsFeed` | `O(T log T)` | `O(T)` | Where `T` is the total number of tweets of the user and their followees. We push all `T` elements to the heap and extract up to 10. |

---

## Edge Cases

| Scenario | Behavior |
| :--- | :--- |
| Self-Unfollow (`unfollow(A, A)`) | Guarded; returns immediately without altering the `following` relationship. |
| User follows someone with no tweets | `tweets.count(followee)` is empty; heap compiles user's own feed correctly. |
| No tweets posted by user or followees | The `feed` heap is empty; returns an empty vector without crashes or issues. |
| Fewer than 10 total tweets | Merges all available tweets and terminates when the heap is empty, returning fewer than 10. |

---

## Files

| File | Description |
| :--- | :--- |
| [`twitter-pq-merge.cpp`](./twitter-pq-merge.cpp) | C++ solution using map-based follow/tweet structures and priority queue feed merging |
| [`getNewsFeed_heap_stepper.html`](./getNewsFeed_heap_stepper.html) | Step-by-step interactive SVG visualization of feed merging using a max-heap |

### Interactive Demo (`getNewsFeed_heap_stepper.html`)

An embeddable, step-by-step visualization demonstrating:
- **Max-heap (pq)** state and items currently loaded.
- Pop operations of the top elements (with largest timestamps).
- The gradual collection of the **top 10 news feed results**.
