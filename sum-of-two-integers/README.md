# Sum of Two Integers

- **Difficulty:** Medium
- **Categories:** Math, Bit Manipulation
- **Time Complexity:** O(1)
- **Space Complexity:** O(1)

---

Calculate the sum of two integers without using + or - operators.

---

## Approach: Bit Manipulation (XOR + Carry)

XOR gives sum without carry. AND shifted left gives carries. Repeat until no carry remains. In Python, handle 32-bit overflow explicitly.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/sum-of-two-integers)
- [LeetCode](https://leetcode.com/problems/sum-of-two-integers/)
