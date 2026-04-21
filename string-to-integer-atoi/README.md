# String to Integer (atoi)

- **Difficulty:** Medium
- **Categories:** String
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Implement the myAtoi function that converts a string to a 32-bit signed integer, handling whitespace, sign, overflow, and non-digit characters.

---

## Approach: Character-by-Character Simulation

Skip leading whitespace, read optional sign, read digits stopping at non-digit. Clamp result to INT_MIN/INT_MAX range to handle overflow.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/string-to-integer-atoi)
- [LeetCode](https://leetcode.com/problems/string-to-integer-atoi/)
