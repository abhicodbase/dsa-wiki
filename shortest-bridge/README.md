# Shortest Bridge

- **Difficulty:** Medium
- **Categories:** Array, Depth-First Search, Breadth-First Search, Matrix
- **Time Complexity:** O(N^2)
- **Space Complexity:** O(N^2)

---

A binary matrix has exactly 2 islands. Find the minimum number of flips to connect them.

---

## Approach: DFS to Find Island 1 + BFS to Expand

DFS to color island 1 and enqueue its cells. BFS outward from island 1 through water cells. Return distance when island 2 is first reached.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/shortest-bridge)
- [LeetCode](https://leetcode.com/problems/shortest-bridge/)
