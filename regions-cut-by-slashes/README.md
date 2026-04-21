# Regions Cut By Slashes

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Union Find, Graph
- **Time Complexity:** O(N^2)
- **Space Complexity:** O(N^2)

---

Count regions in an n x n grid of '/', backslash, ' '. Slashes divide cells into triangular regions.

---

## Approach: Upscale Grid by 3x + DFS/BFS

Expand each cell to a 3x3 block. '/' draws a diagonal, backslash draws the other diagonal. Then count connected components of 0s using DFS/BFS on the 3N x 3N grid.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/regions-cut-by-slashes)
- [LeetCode](https://leetcode.com/problems/regions-cut-by-slashes/)
