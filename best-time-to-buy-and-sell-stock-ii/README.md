# Best Time to Buy and Sell Stock II

- **Difficulty:** Medium
- **Categories:** Array, Greedy, Dynamic Programming
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

You can buy and sell as many times as you like (one transaction at a time). Return maximum profit.

---

## Approach: Greedy (Collect Every Upward Slope)

Add price[i] - price[i-1] to profit whenever it's positive. This is equivalent to capturing every upward price movement.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/best-time-to-buy-and-sell-stock-ii)
- [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
