# Count Complete Tree Nodes

**LeetCode #222** · [LeetCode](https://leetcode.com/problems/count-complete-tree-nodes/) · [NeetCode](https://neetcode.io/problems/count-complete-tree-nodes)

- **Difficulty:** Easy
- **Categories:** Binary Search, Bit Manipulation, Tree, Binary Tree
- **Time Complexity:** O(log² N)
- **Space Complexity:** O(log N)

---

## Problem Statement

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and `2^h` nodes inclusive at the last level `h`.

Design an algorithm that runs in less than `O(N)` time complexity.

**Examples:**
```
Input:  root = [1,2,3,4,5,6]  →  Output: 6
Input:  root = []             →  Output: 0
Input:  root = [1]            →  Output: 1
```

---

## Intuition

A naive solution traverses the entire tree and counts all nodes in $O(N)$ time. However, we can do better by leveraging the properties of a complete binary tree. 

If we compare the left-most height (traversing only left children) with the right-most height (traversing only right children), we can determine if the tree is a perfect binary tree. In a perfect binary tree, the number of nodes is exactly $2^{height} - 1$. 

If the left and right heights are equal, we can compute the node count in $O(1)$ time using bit shifting: `(1 << height) - 1`. If the heights are not equal, we recurse on the left and right subtrees and add 1 for the current root. Since the tree is complete, at least one of the two subtrees is guaranteed to be a perfect binary tree, meaning the height check will succeed there and terminate that branch of recursion.

---

## Approach: Height Comparison

1. Find the left height by traversing `root->left->left...` and counting steps.
2. Find the right height by traversing `root->right->right...` and counting steps.
3. If `leftHeight == rightHeight`, return `(1 << leftHeight) - 1`.
4. Otherwise, return `1 + countNodes(root->left) + countNodes(root->right)`.

```cpp
int getHeight(TreeNode* node) {
    if(node == NULL) return 0;
    TreeNode* leftNode = node;
    int leftHeight = 0, rightHeight = 0;
    while(leftNode != NULL) {
        leftHeight++;
        leftNode = leftNode->left;
    }
    TreeNode* rightNode = node;
    while(rightNode != NULL) {
        rightHeight++;
        rightNode = rightNode->right;
    }
    if(leftHeight == rightHeight) {
        // Can also use bitwise shift: (1 << leftHeight) - 1
        return pow(2, leftHeight) - 1;
    }
    return 1 + getHeight(node->left) + getHeight(node->right);
}

int countNodes(TreeNode* root) {
    return getHeight(root);
}
```

---

## Complexity

| | Value | Reason |
|---|---|---|
| **Time**  | O(log² N) | Finding the height of a tree takes $O(\log N)$ steps. At each level of recursion, we compute heights, and we only descend along one non-perfect boundary path (length $O(\log N)$). |
| **Space** | O(log N) | The maximum recursion depth is equal to the height of the tree, which is $O(\log N)$ for a complete binary tree. |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Empty tree (`root = nullptr`) | Returns `0` (handled by the base case) |
| Single node | Returns `1` (left height = 1, right height = 1, returns `(1<<1) - 1 = 1`) |
| Perfect binary tree | Left and right heights match, returns `2^h - 1` in $O(\log N)$ time without recursion |
| Tree with maximum nodes ($5 \times 10^4$) | Avoids overflow because height $\approx 16$, which easily fits in a standard integer |

---

## Files

| File | Description |
|---|---|
| [`height-comparison.cpp`](./height-comparison.cpp) | Main C++ solution using height comparison |

---

## Related Problems

- [Maximum Depth of Binary Tree (LC #104)](https://leetcode.com/problems/maximum-depth-of-binary-tree/) — Basic tree height computation
- [Balanced Binary Tree (LC #110)](https://leetcode.com/problems/balanced-binary-tree/) — Subtree height comparison logic
- [Check Completeness of a Binary Tree (LC #958)](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) — Verifying complete tree structure properties
