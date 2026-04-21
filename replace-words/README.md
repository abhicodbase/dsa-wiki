# Replace Words

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, String, Trie
- **Time Complexity:** O(S+W)
- **Space Complexity:** O(S)

---

Replace words in a sentence with their shortest root from a given dictionary.

---

## Approach: Trie Prefix Lookup

Build Trie from dictionary roots. For each word in sentence, traverse Trie: if a root end is found, replace word with root. Else keep original word.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/replace-words)
- [LeetCode](https://leetcode.com/problems/replace-words/)
