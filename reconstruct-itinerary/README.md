# Reconstruct Itinerary

- **Difficulty:** Hard
- **Categories:** Depth-First Search, Graph, Eulerian Circuit
- **Time Complexity:** O(E log E)
- **Space Complexity:** O(E)

---

Given a list of airline tickets, reconstruct the itinerary starting from JFK in lexicological order.

---

## Approach: Hierholzer's Algorithm (Euler Path)

Build adjacency list with sorted neighbors (using priority queue). DFS: visit smallest destination, when no more destinations backtrack and add current to result. Reverse result.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/reconstruct-itinerary)
- [LeetCode](https://leetcode.com/problems/reconstruct-itinerary/)
