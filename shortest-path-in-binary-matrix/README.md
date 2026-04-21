# Shortest Path in Binary Matrix

- **Difficulty:** Medium
- **Categories:** Array, Breadth-First Search, Matrix
- **Time Complexity:** O(N²)
- **Space Complexity:** O(N²)

---

Find the shortest path from top-left to bottom-right in an n×n binary matrix moving 8-directionally through 0-cells. Return -1 if no path.

---

## Approach: BFS (8-Directional)

BFS from (0,0) if it's 0. Explore all 8 neighbors, marking visited. Return distance when (n-1,n-1) is reached, or -1 if queue empties.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/shortest-path-in-binary-matrix)
- [LeetCode](https://leetcode.com/problems/shortest-path-in-binary-matrix/)
