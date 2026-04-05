# Two Sum

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

---
### Approach
Use a hash map to store the value and its index. For each number, check if `target - num` exists in the map.
