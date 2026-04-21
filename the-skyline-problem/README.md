# The Skyline Problem

- **Difficulty:** Hard
- **Categories:** Array, Divide and Conquer, Binary Indexed Tree, Segment Tree, Line Sweep, Heap, Priority Queue, Ordered Set
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Given building positions and heights, compute the skyline (outline of buildings against sky).

---

## Approach: Sweep Line with Max-Heap

Create events (x, ±height). Sort. Use max-heap of active building heights. At each x, add/remove heights. If max height changes, record a skyline point.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/the-skyline-problem)
- [LeetCode](https://leetcode.com/problems/the-skyline-problem/)
