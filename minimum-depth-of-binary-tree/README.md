# Minimum Depth of Binary Tree

- **Difficulty:** Easy
- **Categories:** Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Return the minimum depth of a binary tree (path from root to nearest leaf node).

---

## Approach: BFS (Level Order)

BFS is optimal for minimum depth — return depth at the first leaf node encountered. DFS must handle the edge case where one child is null (not a leaf).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-depth-of-binary-tree)
- [LeetCode](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
