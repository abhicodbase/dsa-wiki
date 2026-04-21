# Check Completeness of a Binary Tree

- **Difficulty:** Medium
- **Categories:** Tree, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Given the root of a binary tree, determine if it is a complete binary tree.

---

## Approach: BFS with Null Flag

BFS the tree. Once a null node is encountered, all subsequent nodes must also be null. If a non-null node appears after a null, it's not complete.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/check-completeness-of-a-binary-tree)
- [LeetCode](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)
