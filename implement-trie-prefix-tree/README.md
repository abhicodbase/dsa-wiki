# Implement Trie (Prefix Tree)

Implement a trie with `insert`, `search`, and `startsWith` operations. A trie (prefix tree) is a tree-like data structure used to efficiently store and retrieve keys in a dataset of strings.

### Complexity
- **Time Complexity**: O(m) per operation, where m is the length of the word
- **Space Complexity**: O(m × n) total, where n is the number of inserted words

---
### Approach
Each `TrieNode` contains an array of 26 child pointers (one per letter) and a boolean `isEnd` flag. `insert` walks the trie character by character, creating new nodes as needed. `search` walks and checks `isEnd` at the last character. `startsWith` walks without checking `isEnd`.
