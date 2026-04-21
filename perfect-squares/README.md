# Perfect Squares

- **Difficulty:** Medium
- **Categories:** Math, Dynamic Programming, Breadth-First Search
- **Time Complexity:** O(N*sqrt(N))
- **Space Complexity:** O(N)

---

Given n, return the minimum number of perfect squares that sum to n.

---

## Approach: BFS (Shortest Path in Implicit Graph)

BFS where each node is a number, edges go to node - k^2 for each perfect square k^2. Minimum steps to reach 0 from n.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/perfect-squares)
- [LeetCode](https://leetcode.com/problems/perfect-squares/)
