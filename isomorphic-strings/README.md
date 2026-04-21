# Isomorphic Strings

- **Difficulty:** Easy
- **Categories:** Hash Table, String
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given strings s and t, determine if they are isomorphic — characters in s can be replaced to get t, preserving order uniquely.

---

## Approach: Bidirectional Mapping

Maintain two maps: s→t and t→s. For each pair (cs, ct), verify both maps are consistent. If any conflict is found, return false.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/isomorphic-strings)
- [LeetCode](https://leetcode.com/problems/isomorphic-strings/)
