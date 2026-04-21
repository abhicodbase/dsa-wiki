# All Nodes Distance K in Binary Tree

- **Difficulty:** Medium
- **Categories:** Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Find all nodes at distance k from a given target node in a binary tree.

---

## Approach: BFS on Graph (with Parent Pointers)

DFS to record parent pointers for each node. Then BFS from target node treating the tree as an undirected graph, traversing child and parent edges. Collect nodes at depth k.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/all-nodes-distance-k-in-binary-tree)
- [LeetCode](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
