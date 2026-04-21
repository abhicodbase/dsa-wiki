# K Closest Points to Origin

- **Difficulty:** Medium
- **Categories:** Array, Math, Divide and Conquer, Sorting, Heap, Priority Queue, Quickselect
- **Time Complexity:** O(N log K)
- **Space Complexity:** O(K)

---

Given an array of points, return the k closest points to the origin (0, 0).

---

## Approach: Max-Heap of Size K

Maintain a max-heap of size k (by squared distance). For each point, push it. If heap exceeds k, pop the farthest. Final heap contains k closest points.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/k-closest-points-to-origin)
- [LeetCode](https://leetcode.com/problems/k-closest-points-to-origin/)
