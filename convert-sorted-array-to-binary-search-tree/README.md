# Convert Sorted Array to Binary Search Tree

- **Difficulty:** Easy
- **Categories:** Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **Divide and Conquer (Midpoint as Root)** | $O(N)$ | $O(\log N)$ | Picks middle element as root recursively to ensure height balance. |

---

Given an integer array `nums` where the elements are sorted in **ascending order**, convert it to a **height-balanced** binary search tree (BST).

A **height-balanced** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

**Examples:**
```text
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted.

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
```

---

## Approach: Divide and Conquer (Midpoint as Root)

1. **Intuition**: 
   - Since `nums` is sorted, picking the **middle element** (`nums[mid]`) guarantees that half of the remaining elements lie to the left (all smaller) and half lie to the right (all larger).
   - This ensures the left subtree and right subtree will have equal or near-equal heights, maintaining a **height-balanced BST**.

2. **Recursive Construction**:
   - **Base Case**: `if (start > end) return nullptr;`
   - **Midpoint**: `mid = start + (end - start) / 2;`
   - **Create Node**: `TreeNode* node = new TreeNode(nums[mid]);`
   - **Recursive Subtrees**:
     - `node->left = BSTConstruct(nums, start, mid - 1);`
     - `node->right = BSTConstruct(nums, mid + 1, end);`

---

## Files

| File | Description |
| :--- | :--- |
| [`solution.cpp`](./solution.cpp) | C++ solution using Divide and Conquer |

---

## Learn More
- [NeetCode](https://neetcode.io/problems/convert-sorted-array-to-binary-search-tree)
- [LeetCode](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
