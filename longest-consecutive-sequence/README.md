# Longest Consecutive Sequence

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Union Find
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given an unsorted array, return the length of the longest consecutive elements sequence. Must run in O(N) time.

---

## Approach: Hash Set

Insert all numbers into a set. For each number, only start counting if num-1 is NOT in the set (it's a sequence start). Then extend the streak greedily.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/longest-consecutive-sequence)
- [LeetCode](https://leetcode.com/problems/longest-consecutive-sequence/)
