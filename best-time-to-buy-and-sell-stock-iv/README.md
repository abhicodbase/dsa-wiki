# Best Time to Buy and Sell Stock IV

- **Difficulty:** Hard
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N×K)
- **Space Complexity:** O(K)

---

You may complete at most k transactions. Return maximum profit.

---

## Approach: DP with K Transactions

Maintain dp[k][2] where dp[i][0] = max profit on i-th transaction not holding, dp[i][1] = holding. Transition similar to Stock III but generalized to k.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/best-time-to-buy-and-sell-stock-iv)
- [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)
