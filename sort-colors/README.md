# Sort Colors

- **Difficulty:** Medium
- **Categories:** Array, Two Pointers, Sorting
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given an array with values 0 (red), 1 (white), 2 (blue), sort them in-place in a single pass.

---

## Approach: Dutch National Flag (3-Way Partition)

Maintain three pointers: low, mid, high. If nums[mid]=0, swap with low and advance both. If 1, advance mid. If 2, swap with high and retreat high. One pass.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/sort-colors)
- [LeetCode](https://leetcode.com/problems/sort-colors/)
