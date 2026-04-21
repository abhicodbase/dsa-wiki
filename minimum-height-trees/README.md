# Minimum Height Trees

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Graph, Topological Sort
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Find all roots that minimize the height of the resulting tree.

---

## Approach: Topological Sort (Leaf Trimming)

Iteratively remove leaf nodes (degree 1). The last 1 or 2 remaining nodes are the roots of minimum height trees.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-height-trees)
- [LeetCode](https://leetcode.com/problems/minimum-height-trees/)
