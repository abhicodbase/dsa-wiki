# H-Index

- **Difficulty:** Medium
- **Categories:** Array, Sorting, Counting Sort
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(1)

---

Given citation counts, find h-index: the max h such that h papers have at least h citations each.

---

## Approach: Sort Descending + Linear Scan

Sort descending. For each index i (0-based), if citations[i] >= i+1, h = i+1. The answer is the maximum such i+1.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/h-index)
- [LeetCode](https://leetcode.com/problems/h-index/)
