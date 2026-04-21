# Factorial Trailing Zeroes

- **Difficulty:** Medium
- **Categories:** Math
- **Time Complexity:** O(log N)
- **Space Complexity:** O(1)

---

Given an integer n, return the number of trailing zeroes in n!. Must be O(log N).

---

## Approach: Count Factor 5

Trailing zeros = number of 10 factors = min(count of 2, count of 5). Since 5s are rarer, count = n/5 + n/25 + n/125 + ... until floor goes to 0.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/factorial-trailing-zeroes)
- [LeetCode](https://leetcode.com/problems/factorial-trailing-zeroes/)
