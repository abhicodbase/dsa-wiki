# Minimum Path Sum

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming, Matrix
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Find the path from top-left to bottom-right of a grid that minimizes the sum of all numbers along the path (can only move right or down).

---

## Approach: 2D Bottom-Up DP

dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]). Fill first row and column separately (only one direction available). Answer at dp[m-1][n-1].

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-path-sum)
- [LeetCode](https://leetcode.com/problems/minimum-path-sum/)
