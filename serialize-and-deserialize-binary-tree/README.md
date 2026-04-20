# Serialize and Deserialize Binary Tree

Design an algorithm to serialize a binary tree to a string and deserialize that string back to the original tree structure.

### Complexity
- **Time Complexity**: O(n) for both operations
- **Space Complexity**: O(n)

---
### Approach
Use BFS (level-order) or preorder DFS. During serialization, encode each node's value and use a sentinel (e.g., `"null"`) for `nullptr` children. During deserialization, reconstruct the tree by consuming the encoded tokens in the same traversal order using a queue or recursive calls.
