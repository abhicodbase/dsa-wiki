# Bitwise AND of Numbers Range

- **Difficulty:** Medium
- **Categories:** Bit Manipulation
- **Time Complexity:** O(log N)
- **Space Complexity:** O(1)

---

Given a range [left, right], return the bitwise AND of all numbers in that range.

---

## Approach: Common Prefix of Bits

The result is the common prefix of left and right in binary. Right-shift both until equal (counting shifts). Left-shift the common prefix back by shift count.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/bitwise-and-of-numbers-range)
- [LeetCode](https://leetcode.com/problems/bitwise-and-of-numbers-range/)
