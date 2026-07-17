# Delete Node in a BST

**LeetCode #450** · [LeetCode](https://leetcode.com/problems/delete-node-in-a-bst/) · [NeetCode](https://neetcode.io/problems/delete-node-in-a-bst)

- **Difficulty:** Medium
- **Categories:** Tree, Binary Search Tree, Binary Tree
- **Time Complexity:** O(H)
- **Space Complexity:** O(H)

---

## Problem Statement

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:
1. Search for a node to remove.
2. If the node is found, delete the node.

**Examples:**
```
Input:  root = [5,3,6,2,4,null,7], key = 3    →  Output: [5,4,6,2,null,null,7]
Input:  root = [5,3,6,2,4,null,7], key = 0    →  Output: [5,3,6,2,4,null,7]
```

---

## Intuition

Deleting a node in a Binary Search Tree (BST) relies on preserving the BST property: for any node, all values in its left subtree must be smaller, and all values in its right subtree must be larger.

When we find the node to delete, there are three scenarios depending on its children count:
1. **No children or one child:** We can directly replace the node with its non-empty child (or `nullptr` if it has no children).
2. **Two children:** We cannot simply delete the node as it would orphan two subtrees. Instead, we must find a successor that is close in value to the deleted node. The inorder successor (the smallest node in its right subtree) fits perfectly because it is larger than all elements in the left subtree and smaller than all remaining elements in the right subtree. We swap values and recursively delete the successor from the right subtree.

---

## Approach: BST Deletion (3 Cases)

To implement this:
1. **Search**:
   - If `key < root->val`, recursively delete the node in the left subtree.
   - If `key > root->val`, recursively delete the node in the right subtree.
2. **Delete**:
   - If the node matches `key`:
     - **No left child**: Delete the current node and return its right child.
     - **No right child**: Delete the current node and return its left child.
     - **Two children**: Locate the minimum node in the right subtree. Copy its value to the current node. Then recursively delete that minimum node's value from the right subtree.

```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root; // Avoid memory leak in C++
            return temp;
        }
        if (!root->right) {
            TreeNode* temp = root->left;
            delete root; // Avoid memory leak in C++
            return temp;
        }
        
        // Find inorder successor (min of right subtree)
        TreeNode* curr = root->right;
        while (curr->left) {
            curr = curr->left;
        }
        root->val = curr->val;
        root->right = deleteNode(root->right, curr->val);
    }
    return root;
}
```

---

## Interactive Demo

An interactive step-by-step visualization is available in this folder:
- [Interactive BST Deletion Stepper Demo](./bst_delete_stepper.html)

You can open this HTML file in any browser to visualize the structural changes in a BST as nodes are added or deleted, showcasing how cases 1, 2, and 3 are handled.

---

## Complexity

| | Value | Reason |
|---|---|---|
| **Time**  | O(H) | In the worst case, we search down to the leaf node (height $H$ of the BST) and traverse down to the inorder successor. For a balanced tree, $H = \log N$. For a skewed tree, $H = N$. |
| **Space** | O(H) | The recursive call stack is bounded by the height of the tree $H$. |

---

## Edge Cases

| Scenario | Result |
|---|---|
| Key not in BST | Returns original tree unchanged. |
| Empty tree `root = nullptr` | `nullptr` |
| Deleting leaf node | Safely deletes the node and replaces it with `nullptr`. |
| Deleting root node with only one child | The child becomes the new root. |
| Deleting root node with two children | Root value is replaced by the inorder successor, and successor is removed. |

---

## Files

| File | Description |
|---|---|
| [`bst-deletion.cpp`](./bst-deletion.cpp) | Main C++ solution using a recursive approach with full inline comments and memory leak fixes. |
| [`bst_delete_stepper.html`](./bst_delete_stepper.html) | Step-by-step interactive visualization of deleting a node in a BST. |
| [`README.md`](./README.md) | Problem description, approach documentation, and complexity analysis. |

---

## Related Problems

- [Insert into a Binary Search Tree (LC #701)](https://leetcode.com/problems/insert-into-a-binary-search-tree/) — Rebuilding paths to insert a new node, establishing similar BST traversal logic.
- [Validate Binary Search Tree (LC #98)](https://leetcode.com/problems/validate-binary-search-tree/) — Verifying BST properties, which is crucial to ensure correctness after deletion.
- [Search in a Binary Search Tree (LC #700)](https://leetcode.com/problems/search-in-a-binary-search-tree/) — Traversal and lookup in a BST, matching the search phase of deletion.
