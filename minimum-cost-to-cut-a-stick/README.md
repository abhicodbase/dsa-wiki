# Minimum Cost to Cut a Stick

- **Difficulty:** Hard
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N³)
- **Space Complexity:** O(N²)

---

Given a wooden stick of length n and cut positions, find minimum cost to make all cuts. Cost = length of stick being cut.

---

## Approach: Interval DP

Add 0 and n to cuts, sort. dp[i][j] = min cost to make all cuts between cuts[i] and cuts[j]. For each split point k: dp[i][j] = min(dp[i][k] + dp[k][j] + cuts[j] - cuts[i]).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-cost-to-cut-a-stick)
- [LeetCode](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)
