# Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.

### Complexity
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) (hash map + recursion stack)

---
### Approach
The first element of `preorder` is always the root. Find that root in `inorder` — everything to its left forms the left subtree, and everything to its right forms the right subtree. Recursively apply this logic. Use a hash map to look up inorder indices in O(1).
