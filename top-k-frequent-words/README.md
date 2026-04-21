# Top K Frequent Words

- **Difficulty:** Medium
- **Categories:** Hash Table, String, Trie, Sorting, Bucket Sort, Heap, Counting
- **Time Complexity:** O(N log K)
- **Space Complexity:** O(N)

---

Return the k most frequent words from a list. Sort by frequency descending; ties broken lexicographically.

---

## Approach: Min-Heap of Size K

Count word frequencies. Use a min-heap of size k with custom comparison (frequency ascending, lexicographic descending). Result is the heap contents reversed.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/top-k-frequent-words)
- [LeetCode](https://leetcode.com/problems/top-k-frequent-words/)
