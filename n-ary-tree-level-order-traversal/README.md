# N-ary Tree Level Order Traversal

- **Difficulty:** Medium
- **Categories:** Tree, Breadth-First Search
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given the root of an N-ary tree, return the level order traversal of its nodes' values.

---

## Approach: BFS with Level Tracking

Standard BFS. Process all nodes at current level (enqueued count). For each node, enqueue all its children. Record values for each level.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/n-ary-tree-level-order-traversal)
- [LeetCode](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)
