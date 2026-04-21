# Word Search

- **Difficulty:** Medium
- **Categories:** Array, Backtracking, Matrix, Depth-First Search
- **Time Complexity:** O(M×N×4^L)
- **Space Complexity:** O(L)

---

Search for a word in an m×n grid. Letters must be sequentially adjacent horizontally or vertically. Each cell can be used only once.

---

## Approach: DFS Backtracking on Grid

For each cell matching word[0], DFS in 4 directions. Mark cell as visited (e.g., '#') before recursing, restore after. Return true if all characters matched.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/word-search)
- [LeetCode](https://leetcode.com/problems/word-search/)
