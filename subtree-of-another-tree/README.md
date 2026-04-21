# Subtree of Another Tree

- **Difficulty:** Easy
- **Categories:** Tree, Depth-First Search, String Matching, Binary Tree, Hash Function
- **Time Complexity:** O(M×N)
- **Space Complexity:** O(M+N)

---

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root that has the same structure and node values as subRoot.

---

## Approach: DFS Subtree Matching

At each node of root, check if the subtree rooted there is identical to subRoot using isSameTree. Recurse through all nodes of root.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/subtree-of-another-tree)
- [LeetCode](https://leetcode.com/problems/subtree-of-another-tree/)
