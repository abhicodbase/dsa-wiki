# Distinct Subsequences

- **Difficulty:** Hard
- **Categories:** String, Dynamic Programming
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Count the number of distinct subsequences of s that equal t.

---

## Approach: 2D DP

dp[i][j] = number of times t[0..j-1] appears as subsequence in s[0..i-1]. If s[i-1]==t[j-1]: dp[i][j] = dp[i-1][j-1] + dp[i-1][j]. Else: dp[i][j] = dp[i-1][j].

---

## Learn More
- [NeetCode](https://neetcode.io/problems/distinct-subsequences)
- [LeetCode](https://leetcode.com/problems/distinct-subsequences/)
