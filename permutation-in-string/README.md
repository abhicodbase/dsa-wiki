# Permutation in String

- **Difficulty:** Medium
- **Categories:** Hash Table, Two Pointers, String, Sliding Window
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given strings s1 and s2, return true if any permutation of s1 is a substring of s2.

---

## Approach: Fixed-Size Sliding Window

Maintain a frequency window of size len(s1) over s2. Compare frequency arrays at each position. Match means a permutation exists.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/permutation-in-string)
- [LeetCode](https://leetcode.com/problems/permutation-in-string/)
