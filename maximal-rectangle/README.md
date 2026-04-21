# Maximal Rectangle

- **Difficulty:** Hard
- **Categories:** Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(N)

---

Given a binary matrix, find the largest rectangle containing only 1s and return its area.

---

## Approach: Histogram + Largest Rectangle

Build a heights array treating each row as a histogram base. Apply 'Largest Rectangle in Histogram' using a monotonic stack for each row.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/maximal-rectangle)
- [LeetCode](https://leetcode.com/problems/maximal-rectangle/)
