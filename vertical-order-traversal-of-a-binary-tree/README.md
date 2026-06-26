# Vertical Order Traversal of a Binary Tree

- **Difficulty:** Hard
- **Categories:** Hash Table, Tree, Depth-First Search, Breadth-First Search, Sorting, Binary Tree

---

## Complexity Analysis

- **Time Complexity:** $O(N \log N)$
  - Visiting all $N$ nodes takes $O(N)$ time.
  - Inserting coordinates into a sorted map takes $O(\log C)$ where $C$ is the number of unique columns.
  - Sorting elements within each column takes $O(K \log K)$ where $K$ is the number of elements in a column. Summing this over all columns gives $O(N \log N)$ in the worst case (e.g. when all nodes fall in a few columns or have identical coordinates).
- **Space Complexity:** $O(N)$
  - The hash/sorted map structure holds coordinates for all $N$ nodes.
  - The recursion stack space for Depth-First Search is $O(H)$ where $H$ is the height of the tree, which is $O(N)$ in the worst-case skewed tree.

---

Return the vertical order traversal of a binary tree's values. Nodes at the same (col, row) are sorted by value.

---

## Approach: DFS with (row, col) Annotation

DFS assigning (row, col) to each node: root is at `(0, 0)`, left child is at `(row + 1, col - 1)`, and right child is at `(row + 1, col + 1)`. Group nodes by their column index, and then sort within each group by row index and node value. Finally, output column groups sorted from left to right.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/vertical-order-traversal-of-a-binary-tree)
- [LeetCode](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
