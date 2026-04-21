# Maximal Square

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming, Matrix
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Given an m×n binary matrix, find the largest square containing only 1s and return its area.

---

## Approach: DP (Min of Three Neighbors + 1)

dp[i][j] = side length of largest square with bottom-right at (i,j). If matrix[i][j]='1': dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1. Track max.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/maximal-square)
- [LeetCode](https://leetcode.com/problems/maximal-square/)
