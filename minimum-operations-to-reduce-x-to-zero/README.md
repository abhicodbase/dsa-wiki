# Minimum Operations to Reduce X to Zero

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Binary Search, Sliding Window, Prefix Sum
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Remove elements from either end of nums to make their sum equal to x, in minimum operations.

---

## Approach: Sliding Window (Maximum Middle Subarray)

Reframe: find the longest subarray with sum = totalSum - x. Sliding window for max-length subarray with that target sum. Answer = n - (max_length).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-operations-to-reduce-x-to-zero)
- [LeetCode](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)
