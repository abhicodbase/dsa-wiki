# Range Module

- **Difficulty:** Hard
- **Categories:** Design, Segment Tree, Ordered Set
- **Time Complexity:** O(N) add/rem, O(log N) query
- **Space Complexity:** O(N)

---

Design a module to track ranges of integers with addRange, removeRange, queryRange.

---

## Approach: Sorted Interval List with Merging

Maintain a sorted list of non-overlapping intervals. AddRange: merge all overlapping intervals. RemoveRange: split/trim intervals. QueryRange: check if entire [l, r) is covered.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/range-module)
- [LeetCode](https://leetcode.com/problems/range-module/)
