# Interleaving String

- **Difficulty:** Medium
- **Categories:** String, Dynamic Programming
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M×N)

---

Determine if string s3 is formed by an interleaving of strings s1 and s2.

---

## Approach: 2D DP

dp[i][j] = can s3[0..i+j-1] be interleaved from s1[0..i-1] and s2[0..j-1]? Transition: (s1[i-1]==s3[i+j-1] AND dp[i-1][j]) OR (s2[j-1]==s3[i+j-1] AND dp[i][j-1]).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/interleaving-string)
- [LeetCode](https://leetcode.com/problems/interleaving-string/)
