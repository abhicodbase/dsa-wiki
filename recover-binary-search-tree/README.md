# Recover Binary Search Tree

- **Difficulty:** Medium
- **Categories:** Tree, Depth-First Search, Binary Search Tree, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Two nodes of a BST are swapped by mistake. Recover the tree without changing its structure.

---

## Approach: In-Order Traversal (Morris or Recursive)

In-order traversal should yield sorted order. Detect the two nodes that violate ordering (first where prev > current, second is the current node on second violation). Swap their values.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/recover-binary-search-tree)
- [LeetCode](https://leetcode.com/problems/recover-binary-search-tree/)
