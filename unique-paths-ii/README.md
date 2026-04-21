# Unique Paths II

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming, Matrix
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Like Unique Paths but with obstacles. An obstacle at a cell means no path can pass through it.

---

## Approach: 2D DP with Obstacle Check

Same as Unique Paths DP but set dp[i][j] = 0 if grid[i][j]=1 (obstacle). Otherwise dp[i][j] = dp[i-1][j] + dp[i][j-1].

---

## Learn More
- [NeetCode](https://neetcode.io/problems/unique-paths-ii)
- [LeetCode](https://leetcode.com/problems/unique-paths-ii/)
