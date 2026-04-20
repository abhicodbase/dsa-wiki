# Permutations

Given an array `nums` of distinct integers, return all possible permutations in any order.

### Complexity
- **Time Complexity**: O(n × n!) — there are n! permutations and each takes O(n) to build
- **Space Complexity**: O(n) for the recursion stack (excluding output)

---
### Approach
Use backtracking. At each recursive step, try placing each unused number in the current position, mark it as used, recurse deeper, then unmark (backtrack). Once the current arrangement has `n` elements, add it to the result.
