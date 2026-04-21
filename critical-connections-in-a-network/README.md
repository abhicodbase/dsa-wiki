# Critical Connections in a Network

- **Difficulty:** Hard
- **Categories:** Depth-First Search, Graph, Biconnected Component
- **Time Complexity:** O(V+E)
- **Space Complexity:** O(V+E)

---

Find all critical connections (bridges) in a network — edges whose removal disconnects the graph.

---

## Approach: Tarjan's Bridge Finding Algorithm

DFS assigning discovery times and low values. An edge (u,v) is a bridge if low[v] > disc[u] (v cannot reach u or ancestors without going through u→v).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/critical-connections-in-a-network)
- [LeetCode](https://leetcode.com/problems/critical-connections-in-a-network/)
