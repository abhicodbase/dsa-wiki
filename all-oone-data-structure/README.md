# All O'one Data Structure

- **Difficulty:** Hard
- **Categories:** Hash Table, Linked List, Design, Doubly-Linked List, Ordered Set
- **Time Complexity:** O(1)
- **Space Complexity:** O(N)

---

Design a data structure with inc(key), dec(key), getMaxKey(), getMinKey() all in O(1).

---

## Approach: Doubly Linked List of Frequency Buckets + Hash Map

Doubly linked list where each node is a frequency bucket containing a set of keys. HashMap for key to bucket. Inc/Dec moves key between adjacent buckets.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/all-oone-data-structure)
- [LeetCode](https://leetcode.com/problems/all-oone-data-structure/)
