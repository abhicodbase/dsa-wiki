# Word Search II

- **Difficulty:** Hard
- **Categories:** Array, String, Backtracking, Trie, Matrix
- **Time Complexity:** O(M×N×4×3^L)
- **Space Complexity:** O(W×L)

---

Find all words from a given list that exist in the board (Word Search I rules).

---

## Approach: Trie + DFS Backtracking

Build a Trie from all words. DFS on board: at each cell, follow Trie edges matching cell chars. When a word end is reached, record it. Prune Trie branches to avoid re-visiting.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/word-search-ii)
- [LeetCode](https://leetcode.com/problems/word-search-ii/)
