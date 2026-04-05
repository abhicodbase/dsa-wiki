# Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes, p and q.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(h)

---
### Approach
Use recursion. If the current node is p or q, return it. Recursively search in left and right subtrees. If both return non-null, the current node is the LCA.
