# N-ary Tree Postorder Traversal

- **Difficulty:** Easy
- **Categories:** Stack, Tree, Depth-First Search
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Return the postorder traversal of an N-ary tree (children left-to-right, then root).

---

## Approach: Iterative with Stack + Reverse

Modified pre-order: push root, pop and record, push children left-to-right (so rightmost is processed first). Reverse the result for postorder.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/n-ary-tree-postorder-traversal)
- [LeetCode](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)
