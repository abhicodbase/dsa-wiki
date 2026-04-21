# Max Area of Island

- **Difficulty:** Medium
- **Categories:** Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
- **Time Complexity:** O(MxN)
- **Space Complexity:** O(MxN)

---

Find the maximum area of an island in a binary grid (4-directional connectivity).

---

## Approach: DFS with Area Count

DFS from each unvisited '1', sinking visited cells to '0'. Return area as count of cells visited during DFS. Track and return maximum area found.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/max-area-of-island)
- [LeetCode](https://leetcode.com/problems/max-area-of-island/)
