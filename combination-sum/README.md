# Combination Sum

Given an array of distinct integers `candidates` and a target integer `target`, return all unique combinations of candidates where the chosen numbers sum to `target`. The same number may be chosen unlimited times.

### Complexity
- **Time Complexity**: O(n^(t/m)) where t = target and m = minimum element
- **Space Complexity**: O(t/m) for the recursion depth

---
### Approach
Use backtracking. At each step, try including `candidates[i]` in the current combination and recurse with updated remaining target. Since reuse is allowed, keep the starting index the same. If the target hits 0, add the combination to results. If it goes negative, backtrack.
