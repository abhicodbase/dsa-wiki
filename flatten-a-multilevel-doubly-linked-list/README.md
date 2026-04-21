# Flatten a Multilevel Doubly Linked List

- **Difficulty:** Medium
- **Categories:** Linked List, Depth-First Search, Doubly-Linked List
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Flatten a doubly linked list where nodes may have a child list. The child list should be inserted between the node and its next.

---

## Approach: DFS with Stack

Use a stack. When a node has a child, push next onto stack, connect child as next, null out child. When no next, pop from stack to continue.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/flatten-a-multilevel-doubly-linked-list)
- [LeetCode](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)
