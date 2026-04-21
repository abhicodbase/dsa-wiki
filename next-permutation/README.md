# Next Permutation

Given an array of integers `nums`, rearrange it into the lexicographically next greater permutation. If no such permutation exists (array is descending), rearrange to the lowest possible order (ascending). Must be done in-place with O(1) extra space.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---
### Approach
Three steps:
1. Find the largest index `i` such that `nums[i] < nums[i+1]`. If none, reverse the whole array.
2. Find the largest index `j > i` such that `nums[i] < nums[j]`. Swap `nums[i]` and `nums[j]`.
3. Reverse the suffix starting at `nums[i+1]` to get the smallest possible arrangement for that suffix.
