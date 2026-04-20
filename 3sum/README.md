# 3Sum

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`. The solution set must not contain duplicate triplets.

### Complexity
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1) (excluding output)

---
### Approach
Sort the array. Fix one element at a time and use a two-pointer approach for the remaining pair. Skip duplicate values at each step to avoid duplicate triplets in the result.
