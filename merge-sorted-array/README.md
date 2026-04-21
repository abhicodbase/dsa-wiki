# Merge Sorted Array

- **Difficulty:** Easy
- **Categories:** Array, Two Pointers, Sorting
- **Time Complexity:** O(M+N)
- **Space Complexity:** O(1)

---

Merge nums2 into nums1 in sorted order. nums1 has m+n length with last n spots empty.

---

## Approach: Two Pointers from the Back

Start pointers at m-1 and n-1, writing from position m+n-1 backwards. Always place the larger of the two pointed values. Fill remaining nums2 elements if any.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/merge-sorted-array)
- [LeetCode](https://leetcode.com/problems/merge-sorted-array/)
