# Minimum Genetic Mutation

- **Difficulty:** Medium
- **Categories:** Hash Table, String, BFS
- **Time Complexity:** O(N×M)
- **Space Complexity:** O(N)

---

Given start/end gene strings and a bank of valid mutations, find the minimum number of mutations to transform start to end. One character changes at a time.

---

## Approach: BFS (Unweighted Shortest Path)

Treat each gene string as a node, valid single-character mutations as edges. BFS finds the shortest path from start to end using only genes in the bank.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/minimum-genetic-mutation)
- [LeetCode](https://leetcode.com/problems/minimum-genetic-mutation/)
