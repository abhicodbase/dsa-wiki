# All Nodes Distance K in Binary Tree

- **Difficulty:** Medium
- **Categories:** Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

## Problem Statement
Given a binary tree, a target node `target`, and an integer `k`, return all the values of the nodes that are exactly `k` edges away from the target node. The answer can be returned in any order.

---

## Solution Overview
The tree is treated as an undirected graph:
1. **Parent Mapping (DFS)** – A depth‑first search records the parent of every node in a hash map (`unordered_map<int, TreeNode*>`). This lets us move upwards in the tree.
2. **Breadth‑First Search** – Starting from `target`, we perform a BFS that explores left child, right child, and the parent (if present). A `visited` set prevents revisiting nodes. The BFS stops after `k` levels; the nodes remaining in the queue are exactly at distance `k`.

Both phases run in linear time relative to the number of nodes `N`.

---

## Complexity Analysis
- **Time:** `O(N)` – one DFS to build the parent map and one BFS to locate distance‑`k` nodes.
- **Space:** `O(N)` – storage for the parent map, the BFS queue, and the visited set.

---

## Usage Example
```cpp
TreeNode* root = new TreeNode(3);
root->left = new TreeNode(5);
root->right = new TreeNode(1);
// ... build the rest of the tree ...
TreeNode* target = root->left; // node with value 5
int k = 2;
Solution sol;
vector<int> ans = sol.distanceK(root, target, k);
// ans contains all node values at distance 2 from the target.
```

---

## Learn More
- [NeetCode](https://neetcode.io/problems/all-nodes-distance-k-in-binary-tree)
- [LeetCode](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
