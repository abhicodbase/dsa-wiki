# Minimum Size Subarray Sum

- **Difficulty:** Medium
- **Categories:** Array, Binary Search, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given a positive integer target and array nums, find the minimum length of a subarray whose sum ≥ target.

---

## Approach: Sliding Window

Expand right pointer adding to sum. When sum ≥ target, shrink left pointer to minimize length. Track minimum window length throughout.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-size-subarray-sum)
- [LeetCode](https://leetcode.com/problems/minimum-size-subarray-sum/)
