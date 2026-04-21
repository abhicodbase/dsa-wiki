# Binary Tree Cameras

- **Difficulty:** Hard
- **Categories:** Dynamic Programming, Tree, Depth-First Search, Binary Tree, Greedy
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Place minimum cameras on tree nodes to monitor every node. A camera monitors its parent, itself, and its children.

---

## Approach: Greedy DFS (3 States)

Each node returns: 0 (needs coverage), 1 (has camera), 2 (covered). Post-order: if any child is 0, place camera here (return 1). If any child has camera, return 2. Else return 0.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/binary-tree-cameras)
- [LeetCode](https://leetcode.com/problems/binary-tree-cameras/)
