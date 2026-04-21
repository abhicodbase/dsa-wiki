# Snapshot Array

- **Difficulty:** Medium
- **Categories:** Array, Hash Table, Binary Search, Design
- **Time Complexity:** O(log S) get, O(1) set/snap
- **Space Complexity:** O(N x S)

---

Design an array with set(index, val), snap(), get(index, snap_id) where get returns the value at snap_id snapshot.

---

## Approach: Sparse Changelog + Binary Search

Each index stores a list of (snap_id, value) entries. Set appends to the index's changelog. Get binary searches for the largest snap_id <= given snap_id.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/snapshot-array)
- [LeetCode](https://leetcode.com/problems/snapshot-array/)
