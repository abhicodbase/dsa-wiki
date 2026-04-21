# Intersection of Two Linked Lists

- **Difficulty:** Easy
- **Categories:** Hash Table, Linked List, Two Pointers
- **Time Complexity:** O(M+N)
- **Space Complexity:** O(1)

---

Find the node at which two linked lists intersect. Return null if no intersection.

---

## Approach: Two Pointer Length Equalizer

Use two pointers starting at each head. When one reaches null, redirect it to the other list's head. They meet at the intersection point after traversing M+N total nodes.

---

## Learn More
- [NeetCode](https://neetcode.io/problems/intersection-of-two-linked-lists)
- [LeetCode](https://leetcode.com/problems/intersection-of-two-linked-lists/)
