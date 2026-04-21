# Trapping Rain Water II

- **Difficulty:** Hard
- **Categories:** Array, Breadth-First Search, Heap, Matrix
- **Time Complexity:** O(MxN log(MxN))
- **Space Complexity:** O(MxN)

---

Given an m x n height matrix, compute how much water it can trap after raining (3D version).

---

## Approach: Min-Heap BFS from Border

Push all border cells into a min-heap. BFS inward: the current min-height cell constrains water level. For each neighbor, trapped water = max(0, minHeight - neighbor height). Push updated max-height.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/trapping-rain-water-ii)
- [LeetCode](https://leetcode.com/problems/trapping-rain-water-ii/)
