# Partition Labels

- **Difficulty:** Medium
- **Categories:** Hash Table, Two Pointers, String, Greedy
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Partition a string into as many parts as possible such that each letter appears in at most one part.

---

## Approach: Last Occurrence Greedy

Precompute last occurrence of each character. Greedy: extend current partition to include the last occurrence of every character seen. When current index reaches partition end, record and start new partition.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/partition-labels)
- [LeetCode](https://leetcode.com/problems/partition-labels/)
