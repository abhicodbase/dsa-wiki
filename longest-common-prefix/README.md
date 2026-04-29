# Longest Common Prefix

- **Difficulty:** Easy
- **Categories:** String, Trie, Binary Search

---

## Complexity Analysis

- **Time Complexity:** 
  - **Trie:** $O(S)$, where $S$ is the sum of all characters in all strings. Building the Trie takes $O(S)$, and querying takes $O(M)$ where $M$ is the max prefix length.
  - **Binary Search:** $O(N \cdot M \log M)$, where $N$ is the number of strings and $M$ is the length of the shortest string. We perform binary search on the prefix length ($O(\log M)$ iterations), and in each iteration, we compare $N$ strings up to length $M$.
- **Space Complexity:** 
  - **Trie:** $O(S)$ to store the characters in the worst case (no common prefix).
  - **Binary Search:** $O(1)$ auxiliary space, or $O(M)$ if accounting for string slicing allocations.

---

Find the longest common prefix string among an array of strings.

![Concept](concept.png)

---

## Approach 1: Trie

1. Insert all strings into a Trie data structure.
2. Traverse down the Trie starting from the root.
3. The common prefix stops when we reach a node that either has more than one child (meaning the strings diverge) or marks the end of a word (meaning one of the strings ends there).

---

## Approach 2: Binary Search

1. Find the length of the shortest string, $M$. The longest common prefix cannot exceed this length.
2. Perform a binary search on the range $[0, M]$.
3. For a given `mid` length, check if all strings share the same prefix of length `mid`.
4. If they do, search the right half to see if there's a longer common prefix. If they don't, search the left half.

---

## Related Interview Questions
- [Implement Trie (Prefix Tree)](../implement-trie-prefix-tree/README.md)
- [Design Search Autocomplete System](../design-search-autocomplete-system/README.md)
- [Replace Words](../replace-words/README.md)
- [Word Search II](../word-search-ii/README.md)

---

## Learn More
- [NeetCode](https://neetcode.io/problems/longest-common-prefix)
- [LeetCode](https://leetcode.com/problems/longest-common-prefix/)
