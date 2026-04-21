# Min Cost Climbing Stairs

- **Difficulty:** Easy
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an array cost where cost[i] is the cost to step on stair i, find minimum cost to reach the top. You can start at 0 or 1 and climb 1 or 2 steps.

---

## Approach: Bottom-Up DP

dp[i] = cost[i] + min(dp[i-1], dp[i-2]). Answer is min(dp[n-1], dp[n-2]). Optimize to O(1) space with two variables.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/min-cost-climbing-stairs)
- [LeetCode](https://leetcode.com/problems/min-cost-climbing-stairs/)
