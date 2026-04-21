# Design Add and Search Words Data Structure

- **Difficulty:** Medium
- **Categories:** String, Depth-First Search, Design, Trie
- **Time Complexity:** O(M) add, O(26^M) search
- **Space Complexity:** O(M×N)

---

Design a data structure with addWord and search methods. Search supports '.' wildcard that matches any letter.

---

## Approach: Trie with DFS for Wildcards

Build a standard Trie for addWord. For search: DFS through Trie nodes. On '.', try all 26 children. On character, follow that child if it exists.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/design-add-and-search-words-data-structure)
- [LeetCode](https://leetcode.com/problems/add-and-search-word-data-structure-design/)
