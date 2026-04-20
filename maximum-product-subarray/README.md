# Maximum Product Subarray

Given an integer array `nums`, find a contiguous subarray that has the largest product and return its product.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---
### Approach
Track both the current maximum and minimum product ending at each index (negatives can flip min to max). At each element: `currMax = max(nums[i], nums[i] * prevMax, nums[i] * prevMin)` and similarly for `currMin`. The global answer is the maximum `currMax` seen.
