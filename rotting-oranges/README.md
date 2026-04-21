# Rotting Oranges

- **Difficulty:** Medium
- **Categories:** Array, Breadth-First Search, Matrix
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Grid cells are empty (0), fresh orange (1), or rotten orange (2). Each minute, rotten oranges infect 4-directional neighbors. Return minutes to rot all, or -1 if impossible.

---

## Approach: Multi-Source BFS

Initialize BFS queue with all rotten oranges. BFS spreads rotting simultaneously from all sources. Count minutes (levels). Check if any fresh oranges remain.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/rotting-oranges)
- [LeetCode](https://leetcode.com/problems/rotting-oranges/)
