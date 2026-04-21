# Find First and Last Position of Element in Sorted Array

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** O(log N)
- **Space Complexity:** O(1)

---

Given a sorted array, find the starting and ending position of a given target. Return [-1,-1] if not found.

---

## Approach: Two Binary Searches (Lower & Upper Bound)

Run binary search twice: once biased to find leftmost occurrence (when nums[mid]==target, search left), once biased right. Merge results.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-first-and-last-position-of-element-in-sorted-array)
- [LeetCode](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
