# 01 Matrix

- **Difficulty:** Medium
- **Categories:** Array, Breadth-First Search, Dynamic Programming, Matrix
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Given a binary matrix, return a matrix of distances to the nearest 0 for each cell.

---

## Approach: Multi-Source BFS from All Zeros

Initialize BFS with all 0-cells (distance 0). BFS outward from all zeros simultaneously fills distances for 1-cells layer by layer.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/01-matrix)
- [LeetCode](https://leetcode.com/problems/01-matrix/)
