# Product of Array Except Self

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`. You must solve it without using division and in O(n) time.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1) (excluding the output array)

---
### Approach
Use two passes over the array. In the first pass (left to right), compute the prefix product for each index. In the second pass (right to left), multiply by the suffix product. This avoids division entirely and runs in O(n).
