# Maximum Subarray

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum, and return its sum.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---
### Approach
Use Kadane's Algorithm. Maintain a running `currentSum` and a `maxSum`. At each element, decide whether to extend the current subarray or start fresh. If `currentSum + nums[i] < nums[i]`, then start a new subarray at `nums[i]`.
