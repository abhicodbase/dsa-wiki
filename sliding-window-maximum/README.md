# Sliding Window Maximum

Given an integer array `nums` and a sliding window of size `k`, return the maximum value in each window position as the window moves from left to right.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(k)

---
### Approach
Use a monotonic deque (double-ended queue) that stores indices in decreasing order of their values. For each new element: remove indices from the back that have smaller values (they'll never be the maximum), and remove the front index if it's out of the current window. The front of the deque is always the max of the current window.
