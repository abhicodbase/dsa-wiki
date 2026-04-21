# Graph Valid Tree

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Union Find, Graph
- **Time Complexity:** O(V+E)
- **Space Complexity:** O(V+E)

---

Given n nodes and edges, determine if they form a valid tree (connected + no cycles).

---

## Approach: Union-Find: No Cycle + Single Component

A valid tree has exactly n-1 edges (if different, immediately false). Use Union-Find to process edges; if any edge connects already-connected nodes, there's a cycle.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/graph-valid-tree)
- [LeetCode](https://leetcode.com/problems/graph-valid-tree/)
