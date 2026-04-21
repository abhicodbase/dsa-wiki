# Two Sum II - Input Array Is Sorted

- **Difficulty:** Medium
- **Categories:** Array, Two Pointers, Binary Search
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given a 1-indexed sorted array `numbers`, find two numbers that add up to `target` and return their 1-indexed positions.

---

## Approach: Two Pointers

Start with left pointer at index 0 and right pointer at the last index. If sum < target, move left right; if sum > target, move right left; if equal, return indices.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/two-sum-ii)
- [LeetCode](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
