# Meeting Rooms II

Given an array of meeting time intervals `intervals[i] = [start, end]`, return the minimum number of conference rooms required to hold all meetings simultaneously.

### Complexity
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)

---
### Approach
Sort intervals by start time. Use a min-heap to track end times of ongoing meetings. For each new meeting, if its start time >= the earliest ending meeting, reuse that room (pop and push updated end). Otherwise, allocate a new room. The heap size at the end is the answer.
