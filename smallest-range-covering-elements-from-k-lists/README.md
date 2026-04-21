# Smallest Range Covering Elements from K Lists

- **Difficulty:** Hard
- **Categories:** Array, Hash Table, Greedy, Sliding Window, Sorting, Heap, Priority Queue
- **Time Complexity:** O(N log K)
- **Space Complexity:** O(K)

---

Find the smallest range [a, b] such that at least one element from each of the K lists falls within [a, b].

---

## Approach: Min-Heap with Max Tracking

Initialize heap with first element from each list. Track current max. Pop min, update range [min, max]. Push next from same list. Repeat until any list is exhausted.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/smallest-range-covering-elements-from-k-lists)
- [LeetCode](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)
