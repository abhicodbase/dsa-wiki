# Design Search Autocomplete System

- **Difficulty:** Hard
- **Categories:** String, Design, Trie, Data Stream, Sorting
- **Time Complexity:** O(prefix_len + N log N)
- **Space Complexity:** O(N×L)

---

Design search autocomplete: type characters one by one, return top 3 historical sentences with matching prefix sorted by frequency.

---

## Approach: Trie + Frequency Map

Trie stores sentence prefixes; each node tracks matching sentences and frequencies. On each character input, traverse Trie and return top-3 by frequency (then lexicographic). On '#', add completed sentence.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/design-search-autocomplete-system)
- [LeetCode](https://leetcode.com/problems/design-search-autocomplete-system/)
