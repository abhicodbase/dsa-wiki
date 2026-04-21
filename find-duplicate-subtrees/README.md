# Find Duplicate Subtrees

- **Difficulty:** Medium
- **Categories:** Hash Table, Tree, Depth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Find all duplicate subtrees in a binary tree. Return the root of each duplicate type.

---

## Approach: Serialize + Hash Map

Post-order DFS to serialize each subtree as a string. Use a map: serialization to count. When count becomes 2, add root to result.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-duplicate-subtrees)
- [LeetCode](https://leetcode.com/problems/find-duplicate-subtrees/)
