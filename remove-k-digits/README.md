# Remove K Digits

- **Difficulty:** Medium
- **Categories:** String, Stack, Greedy, Monotonic Stack
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Remove k digits from a number string to make it the smallest possible number. Return as string without leading zeros.

---

## Approach: Monotonic Stack (Greedy)

Use a stack. For each digit, while k>0 and stack top > current digit, pop (remove a digit). Push current. Remove remaining from top if k>0. Strip leading zeros.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/remove-k-digits)
- [LeetCode](https://leetcode.com/problems/remove-k-digits/)
