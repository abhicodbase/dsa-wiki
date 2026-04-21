# Peak Index in a Mountain Array

- **Difficulty:** Medium
- **Categories:** Array, Binary Search
- **Time Complexity:** O(log N)
- **Space Complexity:** O(1)

---

A mountain array strictly increases then strictly decreases. Find the peak index.

---

## Approach: Binary Search on Slope

If nums[mid] < nums[mid+1], peak is to the right — move lo = mid+1. Else peak is at mid or left — move hi = mid. Loop until lo==hi.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/peak-index-in-a-mountain-array)
- [LeetCode](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
