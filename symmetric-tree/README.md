# Symmetric Tree

- **Difficulty:** Easy
- **Categories:** Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Check if a binary tree is a mirror of itself (symmetric around its center).

---

## Approach: Recursive Mirror Check

A tree is symmetric if isMirror(left, right) is true: both null → true; one null → false; values equal AND isMirror(left.left, right.right) AND isMirror(left.right, right.left).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/symmetric-tree)
- [LeetCode](https://leetcode.com/problems/symmetric-tree/)
