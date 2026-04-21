# Find Eventual Safe States

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Graph, Topological Sort
- **Time Complexity:** O(V+E)
- **Space Complexity:** O(V+E)

---

Find all safe nodes in a directed graph — nodes from which every path leads to a terminal node (no cycle).

---

## Approach: Reverse Graph + Topological Sort

Reverse all edges. Nodes with out-degree 0 in original (terminal) are initial safe nodes. BFS/Kahn's on reversed graph: node becomes safe when all its out-edges in original go to safe nodes.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-eventual-safe-states)
- [LeetCode](https://leetcode.com/problems/find-eventual-safe-states/)
