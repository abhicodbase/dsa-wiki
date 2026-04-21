# Number of Connected Components in an Undirected Graph

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Union Find, Graph
- **Time Complexity:** O(V+E)
- **Space Complexity:** O(V+E)

---

Given n nodes and a list of edges, count the number of connected components in the graph.

---

## Approach: Union-Find (DSU)

Initialize each node as its own parent. For each edge, union the two nodes. Count nodes where find(i) == i (distinct roots) — each is a connected component.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/number-of-connected-components)
- [LeetCode](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
