# Number of Provinces

- **Difficulty:** Medium
- **Categories:** Depth-First Search, Breadth-First Search, Union Find, Graph
- **Time Complexity:** O(N^2)
- **Space Complexity:** O(N)

---

Given an n x n adjacency matrix, count the number of provinces (connected components).

---

## Approach: Union-Find

For each pair (i,j) where isConnected[i][j]=1, union i and j. Count unique roots (nodes where find(i)==i).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/number-of-provinces)
- [LeetCode](https://leetcode.com/problems/number-of-provinces/)
