# Count Sub Islands

- **Difficulty:** Medium
- **Categories:** Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
- **Time Complexity:** O(MxN)
- **Space Complexity:** O(MxN)

---

Count islands in grid2 that are also entirely contained within an island in grid1.

---

## Approach: DFS with Both-Grid Check

DFS any '1' in grid2. During DFS, check if corresponding grid1 cell is '0' -- if so, mark this island as invalid (not a sub-island). Count valid islands.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/count-sub-islands)
- [LeetCode](https://leetcode.com/problems/count-sub-islands/)
