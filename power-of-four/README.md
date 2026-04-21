# Power of Four

- **Difficulty:** Easy
- **Categories:** Math, Bit Manipulation, Recursion
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

Return true if n is a power of four.

---

## Approach: Bit Manipulation Check

Powers of four have exactly one set bit in odd positions. Check: n > 0 AND (n & (n-1))==0 (power of two) AND (n & 0xAAAAAAAA)==0 (bit is in even position from right).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/power-of-four)
- [LeetCode](https://leetcode.com/problems/power-of-four/)
