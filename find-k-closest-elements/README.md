# Find K Closest Elements

- **Difficulty:** Medium
- **Categories:** Array, Two Pointers, Binary Search, Sorting, Sliding Window, Heap
- **Time Complexity:** O(log(N-K) + K)
- **Space Complexity:** O(1)

---

Find k integers closest to x in a sorted array (by absolute difference, ties broken by smaller value).

---

## Approach: Binary Search for Left Bound of Window

Binary search for the starting position of the k-element window. Compare arr[mid] vs arr[mid+k] distances to x. Left bound gives the window [lo, lo+k).

---

## Learn More
- [NeetCode](https://neetcode.io/problems/find-k-closest-elements)
- [LeetCode](https://leetcode.com/problems/find-k-closest-elements/)
