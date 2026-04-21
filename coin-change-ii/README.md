# Coin Change II

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(Amount×N)
- **Space Complexity:** O(Amount)

---

Return the number of combinations (not permutations) that make up the amount using given coin denominations.

---

## Approach: Unbounded Knapsack (Combinations)

dp[0]=1. For each coin, iterate amount from coin to target: dp[j] += dp[j-coin]. Outer loop on coins ensures combinations (not permutations).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/coin-change-ii)
- [LeetCode](https://leetcode.com/problems/coin-change-ii/)
