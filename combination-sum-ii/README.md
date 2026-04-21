# Combination Sum II

- **Difficulty:** Medium
- **Categories:** Array, Backtracking
- **Time Complexity:** O(2^N)
- **Space Complexity:** O(N)

---

Given an array of candidates (may have duplicates) and a target, find all unique combinations summing to target. Each candidate used once.

---

## Approach: Backtracking with Sort + Skip Duplicates

Sort candidates. Backtrack with start index. Skip candidates[i] if i > start and candidates[i] == candidates[i-1] (duplicate at same level). Subtract from remaining target.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/combination-sum-ii)
- [LeetCode](https://leetcode.com/problems/combination-sum-ii/)
