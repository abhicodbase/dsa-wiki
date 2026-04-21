# Making a Large Island

- **Difficulty:** Hard
- **Categories:** Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
- **Time Complexity:** O(N^2)
- **Space Complexity:** O(N^2)

---

Flip at most one 0 to 1 in a binary grid. Return the size of the largest possible island.

---

## Approach: Union-Find + 0-Cell Neighbor Check

Use Union-Find to compute island sizes. For each 0-cell, check 4 neighbors island components. Sum unique component sizes + 1. Track maximum.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/making-a-large-island)
- [LeetCode](https://leetcode.com/problems/making-a-large-island/)
