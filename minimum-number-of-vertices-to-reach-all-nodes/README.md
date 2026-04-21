# Minimum Number of Vertices to Reach All Nodes

- **Difficulty:** Medium
- **Categories:** Graph
- **Time Complexity:** O(N+E)
- **Space Complexity:** O(N)

---

Find the smallest set of vertices from which all nodes are reachable in a DAG.

---

## Approach: Nodes with No Incoming Edges

In a DAG, any node with in-degree 0 must be in the source set (no other node can reach it). Return all nodes with in-degree 0.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-number-of-vertices-to-reach-all-nodes)
- [LeetCode](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/)
