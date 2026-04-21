# Maximum Depth of Binary Tree

- **Difficulty:** Easy
- **Categories:** Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Given the root of a binary tree, return its maximum depth (number of nodes along the longest path from root to farthest leaf).

---

## Approach: DFS (Recursive)

Return 1 + max(maxDepth(left), maxDepth(right)) at each node. Base case: null node returns 0.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/maximum-depth-of-binary-tree)
- [LeetCode](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
