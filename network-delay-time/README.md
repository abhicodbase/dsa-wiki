# Network Delay Time

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Graph, Heap, Shortest Path
- **Time Complexity:** O((V+E) log V)
- **Space Complexity:** O(V+E)

---

Given n nodes, weighted directed edges, and a source node k, find the time for all nodes to receive signal. Return -1 if impossible.

---

## Approach: Dijkstra's Algorithm

Use a min-heap of (distance, node). Greedily expand the closest unvisited node, updating distances to neighbors. Return max distance among all nodes.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/network-delay-time)
- [LeetCode](https://leetcode.com/problems/network-delay-time/)
