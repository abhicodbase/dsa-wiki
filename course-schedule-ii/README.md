# Course Schedule II

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Graph, Topological Sort
- **Time Complexity:** O(V+E)
- **Space Complexity:** O(V+E)

---

Given numCourses and prerequisites, return an ordering of courses you should take to finish all. If impossible, return [].

---

## Approach: Kahn's Algorithm (BFS Topological Sort)

Build in-degree array and adjacency list. Initialize queue with 0-in-degree nodes. BFS dequeues nodes, appends to order, decrements neighbors' in-degree, enqueues zeros. If order length ≠ numCourses, cycle exists.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/course-schedule-ii)
- [LeetCode](https://leetcode.com/problems/course-schedule-ii/)
