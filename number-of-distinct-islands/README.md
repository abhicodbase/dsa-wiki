# Number of Distinct Islands

- **Difficulty:** Medium
- **Categories:** Hash Table, Depth-First Search, Breadth-First Search, Union Find, Hash Function
- **Time Complexity:** O(MxN)
- **Space Complexity:** O(MxN)

---

Count the number of distinct island shapes in a binary grid. Two islands are the same if one can be translated to match the other.

---

## Approach: DFS Path Signature Hashing

DFS each island recording directional moves and backtrack markers as a string signature. Translate to relative coordinates. Use a hash set of signatures to count distinct shapes.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/number-of-distinct-islands)
- [LeetCode](https://leetcode.com/problems/number-of-distinct-islands/)
