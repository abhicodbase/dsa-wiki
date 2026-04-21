# Cheapest Flights Within K Stops

- **Difficulty:** Medium
- **Categories:** Dynamic Programming, Depth-First Search, Breadth-First Search, Graph, Heap, Shortest Path
- **Time Complexity:** O(E×K)
- **Space Complexity:** O(V×K)

---

Find cheapest price from src to dst using at most k stops.

---

## Approach: Bellman-Ford (K Relaxations)

Run Bellman-Ford for exactly k+1 iterations (relaxing all edges each time). Use a copy of distances array per iteration to ensure we don't use more than k+1 edges.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/cheapest-flights-within-k-stops)
- [LeetCode](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
