# Subsets

Given an integer array `nums` of unique elements, return all possible subsets (the power set). The solution set must not contain duplicate subsets.

### Complexity
- **Time Complexity**: O(n × 2ⁿ) — 2ⁿ subsets, each taking O(n) to copy
- **Space Complexity**: O(n) for the recursion stack (excluding output)

---
### Approach
Use backtracking. At each index, make two choices: include or exclude the current element. Recurse for both. Add the current subset to results at every step (not just at leaf nodes) to capture all subset sizes including the empty set.
