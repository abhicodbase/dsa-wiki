# Subsets II

- **Difficulty:** Medium
- **Categories:** Array, Backtracking, Bit Manipulation
- **Time Complexity:** O(N × 2^N)
- **Space Complexity:** O(N)

---

Given an integer array that may contain duplicates, return all possible unique subsets.

---

## Approach: Backtracking with Sort + Skip Duplicates

Sort input. In backtracking, at each level skip elements equal to previous element (at the same recursive level, not globally). This ensures unique subsets.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/subsets-ii)
- [LeetCode](https://leetcode.com/problems/subsets-ii/)
