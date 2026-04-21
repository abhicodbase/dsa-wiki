# Sum Root to Leaf Numbers

- **Difficulty:** Medium
- **Categories:** Tree, Depth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Each root-to-leaf path represents a number. Return the total sum of all such numbers.

---

## Approach: DFS with Running Number

Pass current number (currentNum * 10 + node.val) down the tree. At a leaf, return the current number. Sum returned values from left and right subtrees.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/sum-root-to-leaf-numbers)
- [LeetCode](https://leetcode.com/problems/sum-root-to-leaf-numbers/)
