# Walls and Gates

- **Difficulty:** Medium
- **Categories:** Array, Breadth-First Search, Matrix
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

You are given a m×n grid with walls (-1), gates (0), or empty rooms (INF). Fill each empty room with its distance to nearest gate.

---

## Approach: Multi-Source BFS from Gates

Initialize BFS queue with all gates. BFS from all gates simultaneously updates room distances. Each room is visited only once at its minimum distance.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/walls-and-gates)
- [LeetCode](https://leetcode.com/problems/walls-and-gates/)
