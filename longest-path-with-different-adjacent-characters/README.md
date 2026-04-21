# Longest Path with Different Adjacent Characters

- **Difficulty:** Hard
- **Categories:** Array, String, Tree, Depth-First Search, Graph, Topological Sort
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Find the length of the longest path in a tree where no two adjacent nodes have the same character.

---

## Approach: DFS with Two Longest Arms

Post-order DFS: for each node, collect the longest paths from children (only if child char != node char). Sum the top two longest + 1. Update global maximum.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/longest-path-with-different-adjacent-characters)
- [LeetCode](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/)
