# Count Complete Tree Nodes

- **Difficulty:** Easy
- **Categories:** Binary Search, Bit Manipulation, Tree, Binary Tree
- **Time Complexity:** O(log²N)
- **Space Complexity:** O(log N)

---

Count nodes in a complete binary tree faster than O(N) by leveraging completeness.

---

## Approach: Binary Search on Last Row

Compute left and right heights. If equal, the left subtree is full: return 2^h - 1 + 1 for right subtree. Otherwise recurse. O(log²N) total.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/count-complete-tree-nodes)
- [LeetCode](https://leetcode.com/problems/count-complete-tree-nodes/)
