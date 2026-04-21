# Alien Dictionary

- **Difficulty:** Hard
- **Categories:** Array, String, Depth-First Search, Breadth-First Search, Graph, Topological Sort
- **Time Complexity:** O(C)
- **Space Complexity:** O(1)

---

Given a sorted list of words in an alien language, determine the order of characters.

---

## Approach: Topological Sort on Character Ordering

Compare adjacent words to extract ordering constraints between characters. Build a directed graph. Run topological sort (DFS/BFS). If cycle detected, return empty string.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/alien-dictionary)
- [LeetCode](https://leetcode.com/problems/alien-dictionary/)
