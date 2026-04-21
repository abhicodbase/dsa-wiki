# Single Number III

- **Difficulty:** Medium
- **Categories:** Array, Bit Manipulation
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Every element appears twice except two. Find both unique elements.

---

## Approach: XOR + Bit Grouping

XOR all → xor_result = a XOR b. Find any set bit in xor_result. Partition numbers into two groups by that bit; XOR each group yields each unique number.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/single-number-iii)
- [LeetCode](https://leetcode.com/problems/single-number-iii/)
