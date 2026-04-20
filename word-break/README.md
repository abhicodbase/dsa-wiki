# Word Break

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

### Complexity
- **Time Complexity**: O(n²), where n is the length of the string
- **Space Complexity**: O(n)

---
### Approach
Use bottom-up DP. Let `dp[i]` = true if `s[0..i-1]` can be segmented using words from the dictionary. For each position `i`, check all substrings ending at `i`. If `dp[j]` is true and `s[j..i-1]` is in the dictionary, set `dp[i] = true`. Return `dp[n]`.
