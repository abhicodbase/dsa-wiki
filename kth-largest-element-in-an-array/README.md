# Kth Largest Element in an Array

Given an integer array `nums` and an integer `k`, return the `kth` largest element in the array.

### Complexity
- **Time Complexity**: O(n log k) using a min-heap, or O(n) average using Quickselect.
- **Space Complexity**: O(k)

---
### Approach
Use a min-priority queue of size k to keep track of the k largest elements seen so far.
