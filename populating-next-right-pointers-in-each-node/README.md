# Populating Next Right Pointers in Each Node

- **Difficulty:** Medium
- **Categories:** Linked List, Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Populate each next pointer to point to its next right node in a perfect binary tree. Use O(1) extra space.

---

## Approach: Level-by-Level using Established Next Pointers

Use curr pointer at each level. Connect curr.left.next = curr.right and curr.right.next = curr.next.left (if next exists). Traverse using next pointers.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/populating-next-right-pointers-in-each-node)
- [LeetCode](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
