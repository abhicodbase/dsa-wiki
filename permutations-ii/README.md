# Permutations II

- **Difficulty:** Medium
- **Categories:** Array, Backtracking
- **Time Complexity:** O(N! × N)
- **Space Complexity:** O(N)

---

Given a collection of numbers that might contain duplicates, return all unique permutations.

---

## Approach: Backtracking with Sort + Skip Duplicates

Sort input. In backtracking, skip a number if it's the same as the previous number and the previous was NOT used (to avoid duplicate permutations at same depth).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/permutations-ii)
- [LeetCode](https://leetcode.com/problems/permutations-ii/)
