# Wiggle Sort II

- **Difficulty:** Medium
- **Categories:** Array, Divide and Conquer, Sorting, Quickselect
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Rearrange array such that nums[0] < nums[1] > nums[2] < nums[3]...

---

## Approach: Median + Virtual Index Mapping

Find median with quickselect. Use 3-way partition with mapped indices (odd positions first, then even) to place elements without equal-elements adjacency issue.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/wiggle-sort-ii)
- [LeetCode](https://leetcode.com/problems/wiggle-sort-ii/)
