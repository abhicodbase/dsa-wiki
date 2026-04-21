# Path Sum II

- **Difficulty:** Medium
- **Categories:** Backtracking, Tree, Depth-First Search, Binary Tree
- **Time Complexity:** O(N²)
- **Space Complexity:** O(N)

---

Find all root-to-leaf paths where the node values sum to targetSum. Return all paths.

---

## Approach: DFS Backtracking

Maintain current path. At each node, add node.val to path. At a leaf with targetSum==0, copy path to result. Backtrack by removing node.val on return.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/path-sum-ii)
- [LeetCode](https://leetcode.com/problems/path-sum-ii/)
