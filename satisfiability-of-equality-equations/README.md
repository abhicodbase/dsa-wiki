# Satisfiability of Equality Equations

- **Difficulty:** Medium
- **Categories:** Array, String, Union Find, Graph
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given equations like 'a==b' and 'c!=d', determine if all equations can be satisfied simultaneously.

---

## Approach: Union-Find on Characters

First pass: union all '==' pairs. Second pass: for '!=' pairs, check if both characters share the same root. If so, contradiction, return false.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/satisfiability-of-equality-equations)
- [LeetCode](https://leetcode.com/problems/satisfiability-of-equality-equations/)
