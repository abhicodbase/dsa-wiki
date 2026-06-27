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

1. **DFS Traversal & Annotation**: We perform a Depth-First Search traversal, passing down `row` and `col` coordinate offsets for every node. The root is placed at `(0, 0)`. When moving left, we transition to `(row + 1, col - 1)`. When moving right, we transition to `(row + 1, col + 1)`.
2. **Column Grouping**: We use a `std::map<int, vector<pair<int, int>>>` where the key represents the column index, and the value is a list of node configurations as `pair<row, node_value>`. Using a `std::map` guarantees that when we iterate over the map, columns are processed in sorted order from left to right.
3. **Sorting within Columns**: For each column, we sort the elements. In C++, sorting a vector of `pair<int, int>` automatically resolves comparisons by:
   - Primary: The first element (`row` value) in ascending order.
   - Secondary (Tie-breaker): The second element (node value `val`) in ascending order.
   This naturally handles the sorting constraint: nodes at the same `(col, row)` coordinate are sorted by value.

---

## Files

| File | Description |
| :--- | :--- |
| [`dfs_with_map.cpp`](./dfs_with_map.cpp) | DFS solution utilizing `std::map` to group coordinates and `std::sort` for row/value ranking |
| [`vertical_order_traversal.html`](./vertical_order_traversal.html) | Interactive step-by-step tree traversal and column bucket visualization |

### Interactive Demo (`vertical_order_traversal.html`)

An embeddable, step-by-step visual demonstration of the vertical traversal:
- The **active node** during Depth-First Search (DFS) traversal.
- The **(row, col) coordinates** computed at each tree node.
- The **column lanes** mapping col indices to visual buckets.
- The **step-by-step column state** showing how values are grouped and sorted.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/vertical-order-traversal-of-a-binary-tree)
- [LeetCode](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
