# Combination Sum IV

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N×Target)
- **Space Complexity:** O(Target)

---

Return the number of possible ordered combinations (permutations) that sum to target using given numbers.

---

## Approach: Permutation DP

dp[0]=1. Outer loop on target amount, inner loop on nums: dp[i] += dp[i-num]. Outer loop on amounts (not nums) counts permutations.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/combination-sum-iv)
- [LeetCode](https://leetcode.com/problems/combination-sum-iv/)
