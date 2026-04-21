# Palindrome Partitioning

- **Difficulty:** Medium
- **Categories:** String, Dynamic Programming, Backtracking
- **Time Complexity:** O(N × 2^N)
- **Space Complexity:** O(N²)

---

Partition a string such that every substring of the partition is a palindrome. Return all possible partitions.

---

## Approach: Backtracking with Palindrome Check

Precompute isPalin[i][j]. Backtrack: at each start position, try all end positions. If s[start..end] is palindrome, add to path and recurse from end+1. Backtrack after.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/palindrome-partitioning)
- [LeetCode](https://leetcode.com/problems/palindrome-partitioning/)
