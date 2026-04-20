# Edit Distance

Given two strings `word1` and `word2`, return the minimum number of operations (insert, delete, replace) required to convert `word1` to `word2`.

### Complexity
- **Time Complexity**: O(m × n)
- **Space Complexity**: O(m × n), reducible to O(n)

---
### Approach
Use a 2D DP table where `dp[i][j]` = minimum edits to convert `word1[0..i-1]` to `word2[0..j-1]`.
- If characters match: `dp[i][j] = dp[i-1][j-1]` (no operation needed)
- Else: `dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])` — delete, insert, or replace respectively.
