# Kth Smallest Element in a BST

- **Difficulty:** Medium
- **Categories:** Tree, Depth-First Search, Binary Search Tree, Binary Tree
- **Time Complexity:** O(H+K)
- **Space Complexity:** O(H)

---

Given a BST root and an integer k, return the k-th smallest value.

---

## Approach: In-Order Traversal (k-th element)

In-order traversal of a BST yields elements in sorted order. Traverse in-order maintaining a counter; return the node's value when counter reaches k.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/kth-smallest-element-in-a-bst)
- [LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
