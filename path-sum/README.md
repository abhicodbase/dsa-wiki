# Path Sum

- **Difficulty:** Easy
- **Categories:** Tree, Depth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Determine if the tree has a root-to-leaf path such that all node values along the path sum to targetSum.

---

## Approach: DFS with Remaining Sum

At each node, subtract node.val from targetSum. At a leaf, check if remaining sum equals 0. Recurse left and right.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/path-sum)
- [LeetCode](https://leetcode.com/problems/path-sum/)
