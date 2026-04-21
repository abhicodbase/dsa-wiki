# Swim in Rising Water

- **Difficulty:** Hard
- **Categories:** Array, Binary Search, Depth-First Search, Breadth-First Search, Union Find, Heap, Matrix
- **Time Complexity:** O(N^2 log N)
- **Space Complexity:** O(N^2)

---

Find the minimum time t to travel from (0,0) to (n-1,n-1) in a grid where you can swim through cells with value <= t.

---

## Approach: Dijkstra / Binary Search + BFS

Treat the problem as finding minimum bottleneck path. Use Dijkstra with priority queue: cost to reach (i,j) = max(cost to predecessor, grid[i][j]).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/swim-in-rising-water)
- [LeetCode](https://leetcode.com/problems/swim-in-rising-water/)
