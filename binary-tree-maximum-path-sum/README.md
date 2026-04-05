# Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. Find the maximum path sum of any non-empty path.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(h) where h is the height of the tree.

---
### Approach
Use recursion. For each node, calculate the maximum contribution it can make to a path passing through its parent, and update the global maximum path sum.
