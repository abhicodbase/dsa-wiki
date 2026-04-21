# Search a 2D Matrix

- **Difficulty:** Medium
- **Categories:** Array, Binary Search, Matrix
- **Time Complexity:** O(log(M×N))
- **Space Complexity:** O(1)

---

Search for a target in an m×n matrix where each row is sorted and the first element of each row > last element of previous row.

---

## Approach: Binary Search (Treat as 1D)

Treat the matrix as a flattened sorted array of size m×n. Binary search on mid, convert index back via row = mid/n, col = mid%n.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/search-a-2d-matrix)
- [LeetCode](https://leetcode.com/problems/search-a-2d-matrix/)
