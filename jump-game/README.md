# Jump Game

You are given an integer array `nums`. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---
### Approach
Use a greedy approach. Keep track of the maximum reachable index as you iterate through the array. If at any point the current index exceeds the maximum reachable index, return false.
