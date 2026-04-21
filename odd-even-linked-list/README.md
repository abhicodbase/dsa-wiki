# Odd Even Linked List

- **Difficulty:** Medium
- **Categories:** Linked List
- **Time Complexity:** O(N)
- **Space Complexity:** O(1)

---

Group all odd-indexed nodes followed by even-indexed nodes in a linked list in-place.

---

## Approach: Two-Pointer Restructuring

Maintain two pointers: odd and even. Weave: odd.next = even.next, advance odd; even.next = odd.next, advance even. Connect odd's tail to even's head.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/odd-even-linked-list)
- [LeetCode](https://leetcode.com/problems/odd-even-linked-list/)
