# Best Time to Buy and Sell Stock with Cooldown

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

After selling, you must wait one day (cooldown) before buying again. Return maximum profit.

---

## Approach: 3-State DP (Hold / Sold / Cooldown)

States: held (holding stock), sold (just sold, in cooldown), rest (not holding, no cooldown). Transition: held = max(held, rest - price); sold = held + price; rest = max(rest, sold).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/best-time-to-buy-and-sell-stock-with-cooldown)
- [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
