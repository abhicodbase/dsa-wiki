# Linked List Cycle II

- **Difficulty:** Medium
- **Categories:** Hash Table, Linked List, Two Pointers
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Given the head of a linked list, return the node where the cycle begins, or null if there's no cycle.

---

## Approach: Floyd's Cycle Detection + Cycle Entry

Detect cycle using slow/fast pointers. When they meet, reset one pointer to head. Advance both one step at a time; they meet at the cycle entry node.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/linked-list-cycle-ii)
- [LeetCode](https://leetcode.com/problems/linked-list-cycle-ii/)
