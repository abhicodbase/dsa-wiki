# Find K Pairs with Smallest Sums

- **Difficulty:** Medium
- **Categories:** Array, Heap, Priority Queue
- **Time Complexity:** O(K log K)
- **Space Complexity:** O(K)

---

Given two sorted arrays, find the k pairs (u, v) — one from each array — with the smallest sums.

---

## Approach: Min-Heap with Index Tracking

Initialize heap with (nums1[i]+nums2[0], i, 0) for all i. Extract min, add to result, push (nums1[i]+nums2[j+1], i, j+1) if j+1 is valid. Repeat k times.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-k-pairs-with-smallest-sums)
- [LeetCode](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)
