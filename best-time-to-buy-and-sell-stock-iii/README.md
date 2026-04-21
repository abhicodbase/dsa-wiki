# Best Time to Buy and Sell Stock III

- **Difficulty:** Hard
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

You may complete at most two transactions. Return maximum profit.

---

## Approach: 4-State DP

Track four states: buy1, sell1, buy2, sell2. Update: buy1 = max(buy1, -price); sell1 = max(sell1, buy1+price); buy2 = max(buy2, sell1-price); sell2 = max(sell2, buy2+price).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/best-time-to-buy-and-sell-stock-iii)
- [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
