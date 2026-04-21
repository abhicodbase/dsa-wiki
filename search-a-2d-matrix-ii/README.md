# Search a 2D Matrix II

- **Difficulty:** Medium
- **Categories:** Array, Binary Search, Divide and Conquer, Matrix
- **Time Complexity:** O(M+N)
- **Space Complexity:** O(1)

---

Search a target in an m×n matrix where each row and column is sorted in ascending order.

---

## Approach: Staircase Search (Top-Right Corner)

Start from top-right corner. If current > target, move left. If current < target, move down. Continue until found or out of bounds.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/search-a-2d-matrix-ii)
- [LeetCode](https://leetcode.com/problems/search-a-2d-matrix-ii/)
