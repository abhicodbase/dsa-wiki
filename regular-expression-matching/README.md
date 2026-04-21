# Regular Expression Matching

- **Difficulty:** Hard
- **Categories:** String, Dynamic Programming, Recursion
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Implement regular expression matching with support for '.' (any char) and '*' (zero or more of preceding element).

---

## Approach: 2D DP (Top-Down or Bottom-Up)

dp[i][j] = does s[0..i-1] match p[0..j-1]? For '*': dp[i][j] = dp[i][j-2] (zero occurrences) OR (s[i-1] matches p[j-2] AND dp[i-1][j]). For '.': match any char.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/regular-expression-matching)
- [LeetCode](https://leetcode.com/problems/regular-expression-matching/)
