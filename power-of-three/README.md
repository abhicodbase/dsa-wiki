# Power of Three

- **Difficulty:** Easy
- **Categories:** Math, Recursion
- **Time Complexity:** O(log₃ N)
- **Space Complexity:** O(1)

---

Return true if n is a power of three.

---

## Approach: Max Power of 3 Divisibility

The largest power of 3 fitting in 32-bit int is 3^19 = 1162261467. n is a power of 3 iff n > 0 AND 1162261467 % n == 0.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/power-of-three)
- [LeetCode](https://leetcode.com/problems/power-of-three/)
