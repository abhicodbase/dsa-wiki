# Balanced Binary Tree

- **Difficulty:** Easy
- **Categories:** Tree, Depth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Determine if a binary tree is height-balanced (every subtree has left/right height differing by at most 1).

---

## Approach: Bottom-Up DFS

Return -1 (unbalanced) or height from each recursive call. If either child returns -1 or heights differ by > 1, propagate -1 upwards. No re-traversal needed.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/balanced-binary-tree)
- [LeetCode](https://leetcode.com/problems/balanced-binary-tree/)
