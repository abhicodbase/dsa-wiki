# Design Twitter

- **Difficulty:** Medium
- **Categories:** Hash Table, Linked List, Design, Heap, Priority Queue
- **Time Complexity:** O(K log N)
- **Space Complexity:** O(U+T)

---

Design a simplified Twitter with postTweet, getNewsFeed (10 most recent from user + followees), follow, unfollow.

---

## Approach: Heap Merge of Per-User Tweet Lists

Store per-user tweet lists (with timestamps). For getNewsFeed, collect recent tweet lists from user + followees, merge using a max-heap on tweet timestamp.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/design-twitter)
- [LeetCode](https://leetcode.com/problems/design-twitter/)
