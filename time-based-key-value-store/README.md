# Time Based Key-Value Store

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Binary Search, Design
- **Time Complexity:** O(log N) get, O(1) set
- **Space Complexity:** O(N)

---

Design a key-value store supporting set(key, value, timestamp) and get(key, timestamp) returning the value with largest timestamp ≤ given timestamp.

---

## Approach: Binary Search on Timestamps

Store a map of key → list of (timestamp, value) pairs (sorted automatically by insertion order). For get, binary search the timestamp list for the largest timestamp ≤ query.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/time-based-key-value-store)
- [LeetCode](https://leetcode.com/problems/time-based-key-value-store/)
