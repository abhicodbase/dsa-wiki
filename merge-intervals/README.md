# Merge Intervals

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals.

### Complexity
- **Time Complexity**: O(n log n) due to sorting
- **Space Complexity**: O(n)

---
### Approach
Sort the intervals by their start time. Iterate through the sorted intervals and merge overlapping ones by updating the end time of the last interval in the result.
