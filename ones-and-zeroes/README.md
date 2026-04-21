# Ones and Zeroes

- **Difficulty:** Medium
- **Categories:** Array, String, Dynamic Programming
- **Time Complexity:** O(L×M×N)
- **Space Complexity:** O(M×N)

---

Given strings with 0s and 1s, find the max number of strings you can form with at most m zeros and n ones.

---

## Approach: 2D 0/1 Knapsack

dp[i][j] = most strings with at most i zeros and j ones. For each string with z zeros and o ones, iterate backwards: dp[i][j] = max(dp[i][j], dp[i-z][j-o] + 1).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/ones-and-zeroes)
- [LeetCode](https://leetcode.com/problems/ones-and-zeroes/)
