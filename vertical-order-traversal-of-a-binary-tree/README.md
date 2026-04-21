# Vertical Order Traversal of a Binary Tree

- **Difficulty:** Hard
- **Categories:** Hash Table, Tree, Depth-First Search, Breadth-First Search, Sorting, Binary Tree
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Return the vertical order traversal of a binary tree's values. Nodes at same (col, row) are sorted by value.

---

## Approach: DFS with (row, col) Annotation

DFS assigning (row, col) to each node: root=(0,0), left child=(row+1, col-1), right child=(row+1, col+1). Group by col, sort within groups by (row, val). Output column groups left to right.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/vertical-order-traversal-of-a-binary-tree)
- [LeetCode](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
