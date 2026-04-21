# Reorganize String

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Greedy, Sorting, Heap, Priority Queue, Counting
- **Time Complexity:** O(N log A)
- **Space Complexity:** O(A)

---

Rearrange string characters so no two adjacent characters are the same. Return any valid arrangement or empty string.

---

## Approach: Greedy with Max-Heap

Count character frequencies. Max-heap by frequency. Alternate: pop most frequent, append to result, hold it, pop next most frequent, append, put held back. Return result or '' if impossible.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/reorganize-string)
- [LeetCode](https://leetcode.com/problems/reorganize-string/)
