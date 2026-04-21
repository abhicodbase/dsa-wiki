# Largest Rectangle in Histogram

- **Difficulty:** Hard
- **Categories:** Array, Stack, Monotonic Stack
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given an array of heights representing histogram bars of width 1, find the area of the largest rectangle.

---

## Approach: Monotonic Stack

Maintain a stack of indices with increasing heights. When a shorter bar is found, pop and calculate area using popped bar as the shortest. Use sentinel values at both ends.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/largest-rectangle-in-histogram)
- [LeetCode](https://leetcode.com/problems/largest-rectangle-in-histogram/)
