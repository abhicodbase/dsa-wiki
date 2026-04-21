# Most Stones Removed with Same Row or Column

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Union Find, Graph
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Stones can be removed if they share a row or column with another stone. Return maximum removable stones.

---

## Approach: Union-Find on Rows and Columns

Union stones sharing a row or column (use offset for columns to avoid collision with row IDs). Each connected component can be reduced to 1 stone. Answer = N - (number of components).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/most-stones-removed-with-same-row-or-column)
- [LeetCode](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)
