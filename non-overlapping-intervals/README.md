# Non-overlapping Intervals

- **Difficulty:** Medium
- **Categories:** Array, Greedy, Sorting
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(1)

---

Given an array of intervals, find the minimum number of intervals to remove to make the rest non-overlapping.

---

## Approach: Greedy (Sort by End Time)

Sort by end time. Greedily keep intervals with the earliest end times. When two intervals overlap, remove the one with the later end time (keep the one already selected). Count removals.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/non-overlapping-intervals)
- [LeetCode](https://leetcode.com/problems/non-overlapping-intervals/)
