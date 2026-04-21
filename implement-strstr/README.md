# Implement strStr() — KMP

- **Difficulty:** Easy
- **Categories:** Two Pointers, String, String Matching
- **Time Complexity:** O(N+M)
- **Space Complexity:** O(M)

---

Given strings haystack and needle, return the index of the first occurrence of needle in haystack, or -1.

---

## Approach: KMP (Knuth-Morris-Pratt)

Build a failure function (LPS array) for needle in O(M). Then scan haystack: on mismatch use the LPS to avoid re-checking characters. O(N) search phase.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/implement-strstr)
- [LeetCode](https://leetcode.com/problems/implement-strstr/)
