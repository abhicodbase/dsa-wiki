# All Paths From Source to Target

- **Difficulty:** Medium
- **Categories:** Backtracking, Depth-First Search, Breadth-First Search, Graph
- **Time Complexity:** O(2^N × N)
- **Space Complexity:** O(2^N × N)

---

Find all paths from node 0 to node n-1 in a DAG.

---

## Approach: DFS Backtracking

DFS from node 0. At each node, explore all neighbors. When node n-1 is reached, record the current path. Backtrack by removing the last node after recursion.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/all-paths-from-source-to-target)
- [LeetCode](https://leetcode.com/problems/all-paths-from-source-to-target/)
