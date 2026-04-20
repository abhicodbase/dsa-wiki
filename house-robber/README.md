# House Robber

You are a robber planning to rob houses along a street. Adjacent houses have security systems connected — robbing two adjacent houses will trigger an alarm. Given an integer array `nums` representing the amount of money in each house, return the maximum amount you can rob without alerting the police.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---
### Approach
Use DP with rolling variables. At each house, decide whether to rob it or skip it: `dp[i] = max(dp[i-1], dp[i-2] + nums[i])`. Since only the previous two values are needed, use two variables (`prev1`, `prev2`) instead of an array.
