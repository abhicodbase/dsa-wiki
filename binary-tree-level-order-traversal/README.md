# Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values (i.e., from left to right, level by level).

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) (queue can hold up to n/2 nodes at the last level)

---
### Approach
Use BFS with a queue. At each step, process all nodes currently in the queue (they all belong to the same level), add their children to the queue, and record the level's values. Repeat until the queue is empty.
