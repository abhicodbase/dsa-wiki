# Single Number II

- **Difficulty:** Medium
- **Categories:** Array, Bit Manipulation
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Every element appears three times except one. Find that one without extra memory.

---

## Approach: Bit Counting (mod 3)

For each bit position, count how many numbers have that bit set. Take count mod 3. The result bits form the unique number.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/single-number-ii)
- [LeetCode](https://leetcode.com/problems/single-number-ii/)
