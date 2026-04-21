# Russian Doll Envelopes

- **Difficulty:** Hard
- **Categories:** Array, Binary Search, Dynamic Programming, Sorting
- **Time Complexity:** O(N log N)
- **Space Complexity:** O(N)

---

Envelopes can be nested if both width and height of one are strictly less than the other. Find the maximum nesting chain.

---

## Approach: Sort + LIS with Binary Search

Sort by width ascending, height descending (so same widths can't nest). Then find LIS on heights using patience sorting / binary search (O(N log N)).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/russian-doll-envelopes)
- [LeetCode](https://leetcode.com/problems/russian-doll-envelopes/)
