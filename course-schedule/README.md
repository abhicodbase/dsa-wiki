# Course Schedule

- **Difficulty:** Medium
- **Categories:** Graphs, Topological Sort, BFS
- **Time Complexity:** O(V + E)
- **Space Complexity:** O(V + E)

---

There are a total of `numCourses` courses you have to take, labeled from 0 to `numCourses - 1`. Some courses may have prerequisites. Determine if it is possible to finish all courses.

---

## Logic Explanation

This is a cycle detection problem in a directed graph. A popular way to solve this is by using **Topological Sorting** via Kahn's algorithm (BFS-based approach).

### Topological Sorting
1. Find all the parents [node having indegree as 0] and add in queue
2. Traverse Graph using BFS and on every visit reduce the indegree of child node, and if it becomes 0 add it in the queue
3. For not detecting cycle - number of parent found during traversal must equal to number of nodes

![Topological Sorting](./concept.png)
