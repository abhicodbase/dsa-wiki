# Container With Most Water

Given `n` non-negative integers `height[i]` representing vertical lines, find two lines that together with the x-axis form a container that holds the most water.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

---
### Approach
Use the two-pointer technique. Start with pointers at both ends of the array. At each step, move the pointer pointing to the shorter line inward — this is the only direction that can potentially increase the area. Track the maximum area seen so far.
