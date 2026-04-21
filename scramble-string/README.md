# Scramble String

- **Difficulty:** Hard
- **Categories:** String, Dynamic Programming
- **Time Complexity:** O(N⁴)
- **Space Complexity:** O(N³)

---

Given two strings s1 and s2, return true if s2 is a scrambled version of s1 (recursively split and possibly swap parts).

---

## Approach: 3D Memoized Recursion / DP

isScramble(s1, s2): for each split point k, check (isScramble(s1[:k], s2[:k]) AND isScramble(s1[k:], s2[k:])) OR swapped versions. Memoize with string pairs.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/scramble-string)
- [LeetCode](https://leetcode.com/problems/scramble-string/)
