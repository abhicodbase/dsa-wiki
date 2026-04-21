# Group Anagrams

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, String, Sorting
- **Time Complexity:** O(N·K log K)
- **Space Complexity:** O(N·K)

---

Given an array of strings, group the anagrams together.

---

## Approach: Sorted String as Key

Sort each string to create a canonical key. Use a hash map from sorted string → group list. Return all groups.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/group-anagrams)
- [LeetCode](https://leetcode.com/problems/group-anagrams/)
