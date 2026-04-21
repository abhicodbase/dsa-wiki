# Fruit Into Baskets

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

You have two baskets, each holding one type of fruit. Pick the maximum number of fruits from a contiguous subarray with at most 2 distinct types.

---

## Approach: Sliding Window with Hash Map

Use a frequency map to track at most 2 distinct fruit types in the current window. When the map exceeds 2 types, shrink the window from the left.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/fruit-into-baskets)
- [LeetCode](https://leetcode.com/problems/fruit-into-baskets/)
