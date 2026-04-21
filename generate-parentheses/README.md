# Generate Parentheses

- **Difficulty:** Medium
- **Categories:** String, Dynamic Programming, Backtracking
- **Time Complexity:** O(4^N / √N)
- **Space Complexity:** O(N)

---

Generate all combinations of n pairs of well-formed parentheses.

---

## Approach: DFS Backtracking (Open/Close Count)

Track open and close counts. Add '(' if open < n. Add ')' if close < open. When both equal n, record result. No need for explicit backtracking since strings are immutable.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/generate-parentheses)
- [LeetCode](https://leetcode.com/problems/generate-parentheses/)
