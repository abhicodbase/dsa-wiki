# Find Minimum in Rotated Sorted Array

Suppose an array of length `n` sorted in ascending order is rotated between 1 and n times. Given the rotated array `nums`, return the minimum element.

### Complexity
- **Time Complexity**: O(log n)
- **Space Complexity**: O(1)

---
### Approach
Use binary search. At each step, compare `mid` with `right`. If `nums[mid] > nums[right]`, the minimum lies in the right half. Otherwise, it lies in the left half (including `mid`). Narrow the range until `left == right`, which is the minimum.
