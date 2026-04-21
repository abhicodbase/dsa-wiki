# Partition Equal Subset Sum

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N×Sum)
- **Space Complexity:** O(Sum)

---

Given a non-empty array, determine if it can be partitioned into two subsets with equal sum.

---

## Approach: 0/1 Knapsack (Boolean DP)

Target = totalSum/2. If odd total, return false. dp[j] = can we make sum j? For each num, iterate j from target to num: dp[j] |= dp[j-num].

---

## Learn More
- [NeetCode](https://neetcode.io/problems/partition-equal-subset-sum)
- [LeetCode](https://leetcode.com/problems/partition-equal-subset-sum/)
