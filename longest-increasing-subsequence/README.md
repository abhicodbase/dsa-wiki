# Longest Increasing Subsequence

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

### Complexity
- **Time Complexity**: O(n log n) using patience sorting; O(n²) using DP
- **Space Complexity**: O(n)

---
### Approach
**DP**: Let `dp[i]` = LIS ending at index `i`. For each `i`, look back at all `j < i` where `nums[j] < nums[i]` and update `dp[i] = max(dp[i], dp[j] + 1)`. Return the max of `dp`.

**Binary Search (Optimal)**: Maintain a `tails` array where `tails[i]` is the smallest tail element of all increasing subsequences of length `i+1`. Use binary search to find the correct position to update. The final length of `tails` is the answer.
