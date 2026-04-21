# Binary Tree Zigzag Level Order Traversal

- **Difficulty:** Medium
- **Categories:** Tree, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Return the zigzag level order traversal of a binary tree (alternating left-to-right and right-to-left per level).

---

## Approach: BFS with Direction Flag

BFS level by level. Maintain a boolean flag. Alternate whether to append or prepend values at each level using a deque or reversing the level's list.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/binary-tree-zigzag-level-order-traversal)
- [LeetCode](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
