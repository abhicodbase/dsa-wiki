# Last Stone Weight

- **Difficulty:** Easy
- **Categories:** Array, Heap, Priority Queue
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Smash the two heaviest stones repeatedly. If they're equal, both are destroyed; otherwise the difference survives. Return the last stone weight or 0.

---

## Approach: Max-Heap

Use a max-heap (priority queue). Each round extract two max stones, push difference if nonzero. Return heap top or 0 if empty.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/last-stone-weight)
- [LeetCode](https://leetcode.com/problems/last-stone-weight/)
