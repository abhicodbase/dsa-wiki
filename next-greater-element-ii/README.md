# Next Greater Element II

- **Difficulty:** Medium
- **Categories:** Array, Stack, Monotonic Stack
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given a circular array, find the next greater element for each element. Wrap around the end.

---

## Approach: Monotonic Stack with Double Pass

Traverse the array twice (0 to 2N) using index modulo. Use a monotonic stack. On second pass, if stack is empty for a position, no greater element exists (answer = -1).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/next-greater-element-ii)
- [LeetCode](https://leetcode.com/problems/next-greater-element-ii/)
