# Surrounded Regions

- **Difficulty:** Medium
- **Categories:** Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Given an m×n board with 'X' and 'O', capture all 'O' regions surrounded by 'X'. 'O's connected to border are not captured.

---

## Approach: DFS/BFS from Border 'O's

Mark all 'O's reachable from border as safe (e.g., 'T'). Then flip all remaining 'O' to 'X' and 'T' back to 'O'.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/surrounded-regions)
- [LeetCode](https://leetcode.com/problems/surrounded-regions/)
