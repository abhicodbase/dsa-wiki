# Binary Tree Right Side View

- **Difficulty:** Medium
- **Categories:** Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Return the values of the nodes you can see when looking at the tree from the right side (rightmost node at each level).

---

## Approach: BFS Level Order (Last Node per Level)

BFS level by level. The last node processed at each level is the rightmost visible node. Add it to result.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/binary-tree-right-side-view)
- [LeetCode](https://leetcode.com/problems/binary-tree-right-side-view/)
