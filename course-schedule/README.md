# Course Schedule

There are a total of `numCourses` courses you have to take, labeled from 0 to `numCourses - 1`. Some courses may have prerequisites. Determine if it is possible to finish all courses.

### Complexity
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V + E)

---
### Approach
This is a cycle detection problem in a directed graph. Use Kahn's algorithm (BFS-based topological sort) or DFS to detect cycles.
