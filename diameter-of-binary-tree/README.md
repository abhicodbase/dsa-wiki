# Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter — the longest path between any two nodes. This path may or may not pass through the root.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(h) where h is the height of the tree (recursion stack)

---
### Approach
Use a post-order DFS. For each node, compute the height of its left and right subtrees. The diameter passing through this node is `leftHeight + rightHeight`. Maintain a global maximum. The recursive function returns the height of the current subtree: `1 + max(leftHeight, rightHeight)`.
