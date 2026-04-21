# Online Stock Span

- **Difficulty:** Medium
- **Categories:** Stack, Design, Monotonic Stack, Data Stream
- **Time Complexity:** O(1) amortized
- **Space Complexity:** O(N)

---

Design a class that collects daily stock prices and returns the span — consecutive days before today (including today) where price was ≤ today's price.

---

## Approach: Monotonic Stack (Price + Span)

Stack of (price, span) pairs. For each new price, pop all entries with price ≤ current price, accumulating their spans. Push (current_price, accumulated_span + 1).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/online-stock-span)
- [LeetCode](https://leetcode.com/problems/online-stock-span/)
