# Minimum Interval to Include Each Query

- **Difficulty:** Hard
- **Categories:** Array, Binary Search, Line Sweep, Sorting, Heap
- **Time Complexity:** O((N+Q) log N)
- **Space Complexity:** O(N+Q)

---

For each query point, find the smallest interval containing it. Return -1 if none.

---

## Approach: Sort + Min-Heap Sweep

Sort intervals and queries. Sweep through sorted queries: add all intervals whose start <= query to a min-heap (by size). Remove intervals whose end < query. Heap top is the smallest valid interval.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-interval-to-include-each-query)
- [LeetCode](https://leetcode.com/problems/minimum-interval-to-include-each-query/)
