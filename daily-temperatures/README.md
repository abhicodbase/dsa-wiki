# Daily Temperatures

- **Difficulty:** Medium
- **Categories:** Array, Stack, Monotonic Stack
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given a daily temperatures array, return an array where answer[i] is the number of days to wait for a warmer temperature.

---

## Approach: Monotonic Stack (Next Greater Element)

Use a stack of indices. For each temperature, pop indices with lower temperatures, setting their answer = current - popped index. Push current index.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/daily-temperatures)
- [LeetCode](https://leetcode.com/problems/daily-temperatures/)
