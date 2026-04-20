# Task Scheduler

Given a list of CPU tasks and a cooldown period `n`, return the minimum number of intervals needed to complete all tasks. The same task must be separated by at least `n` intervals.

### Complexity
- **Time Complexity**: O(m) where m is the number of tasks
- **Space Complexity**: O(1) (at most 26 distinct tasks)

---
### Approach
Count the frequency of each task. The bottleneck is the most frequent task. Calculate idle slots needed: `(maxFreq - 1) * n`. Fill idle slots with other tasks greedily. The answer is `max(total tasks, (maxFreq - 1) * (n + 1) + count of tasks with maxFreq)`.
