# Bus Routes

- **Difficulty:** Hard
- **Categories:** Array, Hash Table, Breadth-First Search
- **Time Complexity:** O(NxM)
- **Space Complexity:** O(NxM)

---

Given bus routes and a source/target stop, find the minimum number of buses to take.

---

## Approach: BFS on Bus Routes (not Stops)

Build map: stop to list of routes. BFS where each node is a bus route (not stop). From current route, get all stops, then all routes through those stops, minimizing bus count.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/bus-routes)
- [LeetCode](https://leetcode.com/problems/bus-routes/)
