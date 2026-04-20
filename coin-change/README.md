# Coin Change

Given an array of coin denominations `coins` and a total amount `amount`, return the fewest number of coins needed to make up that amount. If it cannot be made up, return `-1`.

### Complexity
- **Time Complexity**: O(amount × n), where n is the number of coin denominations
- **Space Complexity**: O(amount)

---
### Approach
Use bottom-up Dynamic Programming. Build a `dp` array of size `amount + 1` initialized to infinity. Set `dp[0] = 0`. For each amount from 1 to `amount`, try every coin denomination and update `dp[i] = min(dp[i], dp[i - coin] + 1)`. Return `dp[amount]` if it's not infinity, else `-1`.
