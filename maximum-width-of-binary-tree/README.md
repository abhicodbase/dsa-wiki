# Maximum Width of Binary Tree

- **Difficulty:** Medium
- **Categories:** Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Find the maximum width of a binary tree (width = number of nodes between leftmost and rightmost nodes at a level, including nulls between).

---

## Approach: BFS with Index Numbering

Assign indices: root=1, left child=2*i, right child=2*i+1. At each level, width = last_index - first_index + 1. BFS level-by-level tracking first/last index.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/maximum-width-of-binary-tree)
- [LeetCode](https://leetcode.com/problems/maximum-width-of-binary-tree/)
