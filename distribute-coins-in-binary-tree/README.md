# Distribute Coins in Binary Tree

- **Difficulty:** Medium
- **Categories:** Tree, Depth-First Search, Binary Tree, Greedy
- **Time Complexity:** O(N)
- **Space Complexity:** O(H)

---

Distribute coins so every node has exactly 1. Each move transfers one coin to adjacent node. Find minimum moves.

---

## Approach: DFS Excess Flow

Post-order DFS: return excess coins (positive=surplus, negative=deficit) from each subtree. Moves += abs(excess) for each subtree. Total moves = sum of all absolute excesses.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/distribute-coins-in-binary-tree)
- [LeetCode](https://leetcode.com/problems/distribute-coins-in-binary-tree/)
