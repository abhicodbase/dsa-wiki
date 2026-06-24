# House Robber III

**LeetCode #337** · [LeetCode](https://leetcode.com/problems/house-robber-iii/) · [NeetCode](https://neetcode.io/problems/house-robber-iii)

- **Difficulty:** Medium
- **Categories:** Dynamic Programming, Tree, Depth-First Search, Binary Tree
- **Time Complexity:** `O(N)` where `N` is the number of nodes in the tree.
- **Space Complexity:** `O(H)` where `H` is the tree height, matching the recursion stack.

---

## Problem Statement

The thief has found himself a new place for his thievery. There is only one entrance to this area, called `root`. Besides the `root`, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if **two directly-linked houses were broken into on the same night**.

Given the `root` of the binary tree, return *the maximum amount of money the thief can rob without alerting the police*.

---

## Intuition

This is a classic dynamic programming problem on trees (Tree DP). For any given node in the tree, we have a choice:
1. **Rob the node**: If we rob the current node, we **cannot** rob its immediate children (left and right). We must add the node's value to the maximum yield we get if we *skip* both children.
2. **Skip the node**: If we skip the current node, we have the flexibility to either rob or skip its children. To maximize our yield, we choose the best result for each child (i.e. `max(rob_child, skip_child)`).

By performing a post-order traversal (DFS), we can compute these choices bottom-up:
- Each DFS call on a node returns a pair of values: `{rob_this_node, skip_this_node}`.
- Once the DFS finishes, the answer is the maximum of the two choices at the root: `max(rob_root, skip_root)`.

This bottom-up approach runs in linear time because we process each node exactly once and don't need memoization tables.

---

## Approach: Bottom-Up Tree DP (Rob vs Skip)

1. Define a recursive helper function `dfs(node)` that returns a pair of integers: `{rob, skip}`.
2. **Base Case**: If `node` is `nullptr`, return `{0, 0}`.
3. **Recursive Call**:
   - Recursively compute the yield for left and right subtrees:
     - `pleft = dfs(node->left)`
     - `pright = dfs(node->right)`
4. **State Transition**:
   - **Rob the node**:
     - `rob = node->val + pleft.second + pright.second` (where `.second` represents the yield when skipping that child).
   - **Skip the node**:
     - `skip = max(pleft.first, pleft.second) + max(pright.first, pright.second)` (taking the best outcome of either robbing or skipping each child).
5. Return `{rob, skip}`.
6. In the main `rob` function, trigger the DFS at the `root` and return `max(p.first, p.second)`.

---

## Code

```cpp
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * Helper function performing Depth-First Search (DFS) for Tree DP.
     * 
     * Returns a pair of integers:
     * - first: The maximum money obtained if we ROB the current node.
     * - second: The maximum money obtained if we SKIP the current node.
     */
    pair<int, int> dfs(TreeNode* node) {
        // Base case: empty node returns 0 for both robbing and skipping
        if(node == NULL) {
            return {0, 0};
        }
        
        // Post-order traversal: compute values bottom-up from children
        pair<int, int> pleft = dfs(node->left);
        pair<int, int> pright = dfs(node->right);
        
        // Scenario 1: Rob the current node
        // If we rob the current node, we MUST skip both its left and right children
        int rob = node->val + pleft.second + pright.second;
        
        // Scenario 2: Skip the current node
        // If we skip the current node, we are free to either rob or skip its children.
        // We choose the maximum possible yield from each subtree.
        int skip = max(pleft.first, pleft.second) + max(pright.first, pright.second);
        
        return {rob, skip};
    }
    
    int rob(TreeNode* root) {
        // Run Tree DP starting at the root
        pair<int, int> p = dfs(root);
        
        // Return the maximum yield between robbing the root or skipping it
        return max(p.first, p.second);
    }
};
```

---

## Complexity

| Complexity | Value | Reason |
| :--- | :--- | :--- |
| **Time** | `O(N)` | We visit each of the `N` nodes exactly once during the post-order traversal. At each node, we perform `O(1)` operations. |
| **Space** | `O(H)` | The call stack space is proportional to the height of the tree `H` (in the worst case of a skewed tree, `H = N`; for a balanced tree, `H = log N`). |

---

## Edge Cases

| Scenario | Behavior |
| :--- | :--- |
| Empty tree (`root == nullptr`) | Returns `0` (base case handles null). |
| Single node tree | Returns the value of that node (robbing it yields `val`, skipping it yields `0`). |
| Tree with only left children (skewed) | Handled correctly; height-bound stack space of size `N`. |
| Zero or negative node values | The `max(rob, skip)` transition handles negative/zero values, deciding to skip them if they decrease overall yields. |

---

## Files

| File | Description |
| :--- | :--- |
| [`tree-dp-rob-vs-skip.cpp`](./tree-dp-rob-vs-skip.cpp) | C++ solution using bottom-up Tree Dynamic Programming |
| [`house_robber_iii_stepper.html`](./house_robber_iii_stepper.html) | Interactive step-by-step visualization of the DP choices propagating up the tree |

### Interactive Demo (`house_robber_iii_stepper.html`)

An embeddable, step-by-step visualization demonstrating:
- The **active node** during post-order traversal.
- The `{rob, skip}` pair returned at each subtree level.
- Highlighting of final decisions (**robbed vs skipped**) on a sample tree: `[3,2,3,null,3,null,1]`.

---

## Related Problems

- [LC #198 — House Robber](https://leetcode.com/problems/house-robber/) — Original 1D array Dynamic Programming
- [LC #213 — House Robber II](https://leetcode.com/problems/house-robber-ii/) — Circular array extension
- [LC #968 — Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/) — Advanced Tree DP with structural parent-child rules
