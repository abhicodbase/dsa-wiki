# Insert into a BST

- **Difficulty:** Medium
- **Categories:** Tree, Binary Search Tree, Binary Tree
- **Time Complexity:** O(H)
- **Space Complexity:** O(H)

---

Insert a value into a BST and return the root of the modified tree.

---

## Approach: Recursive BST Insertion

If root is null, return a new node with the value. If val < root.val, recurse left; if val > root.val, recurse right. Attach result back to appropriate child.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/insert-into-a-binary-search-tree)
- [LeetCode](https://leetcode.com/problems/insert-into-a-binary-search-tree/)
