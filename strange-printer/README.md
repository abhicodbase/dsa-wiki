# Strange Printer

- **Difficulty:** Hard
- **Categories:** String, Dynamic Programming
- **Time Complexity:** O(N³)
- **Space Complexity:** O(N²)

---

A printer can print a sequence of same characters per turn, overwriting previous output. Find minimum turns to print target string.

---

## Approach: Interval DP

dp[i][j] = min turns to print s[i..j]. If s[i]==s[k] for some k in (i,j], we can merge their print turns: dp[i][j] = min(dp[i][k-1] + dp[k][j]) (save one turn).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/strange-printer)
- [LeetCode](https://leetcode.com/problems/strange-printer/)
