# Check Completeness of a Binary Tree

- **Difficulty:** Medium
- **Categories:** Tree, BFS, Binary Tree, Complete Binary Tree
- **Time Complexity:** `O(N)` – each node is visited once during BFS.
- **Space Complexity:** `O(N)` – queue stores at most one level of the tree.

---

## Problem Statement
Given the `root` of a binary tree, determine if it is a **complete binary tree**.

A complete binary tree satisfies:
1. All levels are completely filled except possibly the last level.
2. In the last level, all nodes are as far left as possible.

Return `true` if the tree is complete, otherwise `false`.

---

## Solution Overview
We perform a breadth‑first traversal (BFS) using a queue:
1. Enqueue the root.
2. While processing nodes, once a `nullptr` child is encountered we set a flag `isNullSeen`.
3. After the flag is set, any subsequent non‑null node indicates the tree is not complete → return `false`.
4. If the loop finishes without violation, the tree is complete.

The algorithm works because a complete binary tree, when scanned level‑order, will have all `nullptr` children grouped at the end.

---

## Complexity Analysis
| Metric | Complexity |
|--------|------------|
| Time   | `O(N)` – each node visited once |
| Space  | `O(N)` – queue may hold up to one full level |

---

## Usage Example (C++)
```cpp
#include "bfs.cpp" // contains the Solution class

int main() {
    TreeNode* root = new TreeNode(1,
                      new TreeNode(2,
                          new TreeNode(4),
                          new TreeNode(5)),
                      new TreeNode(3,
                          new TreeNode(6),
                          nullptr));
    Solution sol;
    bool ok = sol.isCompleteTree(root);
    cout << (ok ? "Complete" : "Not complete") << endl; // Expected: Complete
    return 0;
}
```

---

## Learn More
- [LeetCode – Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)
- [Discussion & Editorial](https://leetcode.com/problems/check-completeness-of-a-binary-tree/discuss/)
