# Redundant Connection

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Union Find, Graph
- **Time Complexity:** O(N·α(N))
- **Space Complexity:** O(N)

---

Given a graph with one extra edge (making it have a cycle), find and return that redundant edge.

---

## Approach: Union-Find

Process edges in order. Use Union-Find to union each edge's nodes. The first edge where both nodes already share the same root is the redundant connection.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/redundant-connection)
- [LeetCode](https://leetcode.com/problems/redundant-connection/)
