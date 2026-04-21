# House Robber III

- **Difficulty:** Medium
- **Categories:** Dynamic Programming, Tree, Depth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Rob houses in a binary tree structure. Adjacent nodes (parent-child) cannot both be robbed. Maximize stolen amount.

---

## Approach: Tree DP (Rob vs Skip)

At each node return a pair (robbed, skipped). robbed = node.val + left.skipped + right.skipped. skipped = max(left.robbed, left.skipped) + max(right.robbed, right.skipped).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/house-robber-iii)
- [LeetCode](https://leetcode.com/problems/house-robber-iii/)
