# Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST). A valid BST requires every node's value to be within a valid range — strictly greater than all nodes in its left subtree and strictly less than all nodes in its right subtree.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(h) where h is the height of the tree

---
### Approach
Use recursive DFS with a valid range `[min, max]` for each node. Start with `(-∞, +∞)` for the root. When going left, update `max = current->val`. When going right, update `min = current->val`. Return false if a node's value falls outside its valid range.
