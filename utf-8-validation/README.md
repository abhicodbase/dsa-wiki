# UTF-8 Validation

- **Difficulty:** Medium
- **Categories:** Array, Bit Manipulation
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Validate if an array of integers represents a valid UTF-8 encoding.

---

## Approach: Byte-Pattern Matching

For each lead byte, determine expected continuation bytes (1-4). Verify continuation bytes start with '10'. Process byte groups sequentially.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/utf-8-validation)
- [LeetCode](https://leetcode.com/problems/utf-8-validation/)
