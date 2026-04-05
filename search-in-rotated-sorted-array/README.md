# Search in Rotated Sorted Array

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or -1 if it is not in `nums`.

### Complexity
- **Time Complexity**: O(log n)
- **Space Complexity**: O(1)

---
### Approach
Use binary search. In each step, determine which half of the array is sorted and check if the target lies within the sorted half.
