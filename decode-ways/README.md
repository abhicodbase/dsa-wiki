# Decode Ways

A message containing letters A-Z is encoded as numbers '1'-'26'. Given a string `s` of digits, return the number of ways to decode it.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) (can be optimized to O(1) with two variables)

---
### Approach
Use DP. Let `dp[i]` = number of ways to decode `s[0..i-1]`. At each position, check:
1. If `s[i-1]` is a valid single digit (1–9), add `dp[i-1]`.
2. If `s[i-2..i-1]` is a valid two-digit number (10–26), add `dp[i-2]`.
A leading zero (e.g., "06") is always invalid.
