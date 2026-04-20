# Longest Common Subsequence

Given two strings `text1` and `text2`, return the length of their longest common subsequence. A subsequence is a sequence derived from a string by deleting some characters without changing the relative order of the remaining characters.

### Complexity
- **Time Complexity**: O(m × n), where m and n are the lengths of the two strings
- **Space Complexity**: O(m × n)

---
### Approach
Use a 2D DP table where `dp[i][j]` = LCS length of `text1[0..i-1]` and `text2[0..j-1]`. If characters match, `dp[i][j] = dp[i-1][j-1] + 1`. Otherwise, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`. Return `dp[m][n]`.
