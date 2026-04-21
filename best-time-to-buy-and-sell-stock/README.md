# Best Time to Buy and Sell Stock

- **Difficulty:** Easy
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given prices array, choose a single day to buy and a later day to sell. Return maximum profit. If no profit, return 0.

---

## Approach: One Pass (Track Min Price)

Track the minimum price seen so far. For each day, compute profit = price - minPrice and update max profit. O(N) single pass.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/best-time-to-buy-and-sell-stock)
- [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
