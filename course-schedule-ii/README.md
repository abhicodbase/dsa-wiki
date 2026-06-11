# Course Schedule II

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Graph, Topological Sort
- **Time Complexity:** O(V+E)
- **Space Complexity:** O(V+E)

---

Given `numCourses` and a list of `prerequisites` pairs, return an ordering of courses you should take to finish all. If it is impossible to finish all courses, return an empty array `[]`.

---

## Approach: Kahn's Algorithm (BFS Topological Sort)

We construct an adjacency list and keep track of the **in-degree** (the number of incoming edges/prerequisites) of each node:

1. **Adjacency List & Indegrees**: Iterate through the prerequisites to build the dependency map and count the incoming edges (prerequisites) for each course.
2. **Initialize Queue**: Find all courses that have `0` prerequisites (in-degree is `0`) and push them into the queue.
3. **BFS Process**: 
   - Pop a course from the queue and append it to our topological order list.
   - For each of its dependent courses, decrement their prerequisite count (in-degree).
   - If a course's in-degree drops to `0`, push it onto the queue.
4. **Cycle Detection**: If the resulting ordering does not contain all `numCourses` courses, it indicates a cycle is present in the graph, making it impossible to schedule all courses.

### Interactive Animations
- [Kahn's BFS Topological Sort Animation](./kahns_bfs_topo_sort.html)
- [DFS Topological Sort Animation](./dfs_topo_sort.html)

---

## Learn More
- [NeetCode](https://neetcode.io/problems/course-schedule-ii)
- [LeetCode](https://leetcode.com/problems/course-schedule-ii/)
