# Sum of Distances in Tree

- **Difficulty:** Hard
- **Categories:** Dynamic Programming, Tree, Depth-First Search, Graph, Array
- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

---

Find the sum of distances between all pairs of nodes in an unweighted tree, for each node.

---

## Approach: Two-Pass DFS (Root Down + Re-root)

DFS1 (post-order): compute subtree sizes and distance sums relative to root. DFS2 (pre-order): re-root formula: dist[child] = dist[parent] - count[child] + (N - count[child]).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/sum-of-distances-in-tree)
- [LeetCode](https://leetcode.com/problems/sum-of-distances-in-tree/)
