# Reverse Bits

- **Difficulty:** Easy
- **Categories:** Divide and Conquer, Bit Manipulation
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

Reverse bits of a given 32-bit unsigned integer.

---

## Approach: Bit-by-Bit Reversal

Loop 32 times. Shift result left, OR in (n & 1), shift n right. After 32 iterations, result holds the bit-reversed integer.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/reverse-bits)
- [LeetCode](https://leetcode.com/problems/reverse-bits/)
