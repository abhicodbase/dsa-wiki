# Find the Duplicate Number

- **Difficulty:** Medium
- **Categories:** Array, Two Pointers, Binary Search, Bit Manipulation
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an array of n+1 integers where each is in [1, n], find the one duplicate. Must not modify array. O(1) extra space.

---

## Approach: Floyd's Cycle Detection

Treat array as a linked list where next[i] = nums[i]. A duplicate creates a cycle. Use slow/fast pointers to find cycle entry — that's the duplicate.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-the-duplicate-number)
- [LeetCode](https://leetcode.com/problems/find-the-duplicate-number/)
