# Flatten Binary Tree to Linked List

- **Difficulty:** Medium
- **Categories:** Linked List, Stack, Tree, Depth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Flatten a binary tree to a linked list in-place following pre-order traversal. right pointer acts as next.

---

## Approach: Morris-style (Rightmost of Left Subtree)

For each node with a left child: find rightmost node of left subtree, attach current right to it, move left subtree to right, null left. Advance to right.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/flatten-binary-tree-to-linked-list)
- [LeetCode](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
