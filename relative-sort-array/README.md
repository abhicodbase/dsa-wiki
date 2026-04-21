# Relative Sort Array

- **Difficulty:** Easy
- **Categories:** Array, Hash Table, Sorting, Counting Sort
- **Time Complexity:** O(N + M log M)
- **Space Complexity:** O(N)

---

Reorder arr1 so elements appear in the order defined by arr2. Elements not in arr2 go at the end in ascending order.

---

## Approach: Custom Comparator via Index Map

Map each arr2 element to its index. Sort arr1: elements in arr2 sorted by their arr2 index; others sorted numerically at the end.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/relative-sort-array)
- [LeetCode](https://leetcode.com/problems/relative-sort-array/)
