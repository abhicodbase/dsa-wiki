# Wildcard Matching

- **Difficulty:** Hard
- **Categories:** String, Dynamic Programming, Greedy, Recursion
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Implement wildcard pattern matching where '?' matches any single character and '*' matches any sequence (including empty).

---

## Approach: 2D DP

dp[i][j] = does s[0..i-1] match p[0..j-1]? '*': dp[i][j] = dp[i-1][j] (match one more) OR dp[i][j-1] (match zero). '?'/match: dp[i][j] = dp[i-1][j-1].

---

## Learn More
- [NeetCode](https://neetcode.io/problems/wildcard-matching)
- [LeetCode](https://leetcode.com/problems/wildcard-matching/)
