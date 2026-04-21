# Majority Element II

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Boyer-Moore
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an integer array, return all elements that appear more than ⌊n/3⌋ times.

---

## Approach: Extended Boyer-Moore (2 Candidates)

There can be at most 2 such elements. Use Boyer-Moore with two candidate slots. After the first pass, verify both candidates actually exceed n/3 in a second pass.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/majority-element-ii)
- [LeetCode](https://leetcode.com/problems/majority-element-ii/)
