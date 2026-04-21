# Delete Node in a BST

- **Difficulty:** Medium
- **Categories:** Tree, Binary Search Tree, Binary Tree
- **Time Complexity:** O(H)
- **Space Complexity:** O(H)

---

Delete a node with a given key from a BST and return the root of the modified tree.

---

## Approach: BST Deletion (3 Cases)

Find node. If no left child, return right. If no right child, return left. Otherwise find inorder successor (min of right subtree), replace value, and delete successor from right subtree.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/delete-node-in-a-bst)
- [LeetCode](https://leetcode.com/problems/delete-node-in-a-bst/)
