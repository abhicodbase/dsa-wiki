# Number of Ways to Split a String

- **Difficulty:** Medium
- **Categories:** Math, String, Prefix Sum
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Count ways to split a binary string into 3 non-empty parts with equal number of 1s.

---

## Approach: Count 1s and Find Split Points

Count total 1s. If not divisible by 3, answer is 0. If 0 ones, use combinatorics on gap positions. Otherwise find the gaps between groups of ones at positions total/3 and 2*total/3.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/number-of-ways-to-split-a-string)
- [LeetCode](https://leetcode.com/problems/number-of-ways-to-split-a-string/)
