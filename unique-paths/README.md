# Unique Paths

A robot is located at the top-left corner of an `m x n` grid. The robot can only move right or down. Count the number of unique paths to reach the bottom-right corner.

### Complexity
- **Time Complexity**: O(m × n)
- **Space Complexity**: O(n) (1D DP array)

---
### Approach
Use DP. `dp[i][j]` = number of ways to reach cell `(i, j)` = `dp[i-1][j] + dp[i][j-1]`. The first row and column are all 1s (only one way to reach them). Optimize to O(n) space by using a 1D array and updating in-place.

**Math shortcut**: The answer is C(m+n-2, m-1) — a combinations formula.
