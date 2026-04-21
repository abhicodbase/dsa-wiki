# Number of 1 Bits

- **Difficulty:** Easy
- **Categories:** Divide and Conquer, Bit Manipulation
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

Return the number of '1' bits in the binary representation of an unsigned 32-bit integer (Hamming weight).

---

## Approach: Brian Kernighan's Algorithm

Repeatedly clear the lowest set bit: n = n & (n-1). Count iterations until n = 0. This runs in O(number of set bits) iterations.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/number-of-1-bits)
- [LeetCode](https://leetcode.com/problems/number-of-1-bits/)
