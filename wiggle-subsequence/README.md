# Wiggle Subsequence

- **Difficulty:** Medium
- **Categories:** Array, Dynamic Programming, Greedy
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Find the length of the longest wiggle subsequence (alternating between increasing and decreasing).

---

## Approach: Greedy (Count Direction Changes)

Track previous direction (up/down). Count each time the direction changes. Start count at 1. If nums[i] > nums[i-1] and last direction was not up, increment and switch.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/wiggle-subsequence)
- [LeetCode](https://leetcode.com/problems/wiggle-subsequence/)
